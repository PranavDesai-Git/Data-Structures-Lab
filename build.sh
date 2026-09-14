#!/bin/bash
cd /home/host0/Projects/College/DSA

mkdir -p out
mkdir -p objects

# Clean up previous builds
rm -f out/* objects/* 2>/dev/null || true

compile_folder() {
    folder=$1
    echo "Building $folder..."
    
    c_files=$(find "$folder" -type f -name "*.c")
    if [ -z "$c_files" ]; then
        echo "  No .c files found in $folder"
        return
    fi
    
    lib_o_files=""
    main_o_files=""
    
    for c_file in $c_files; do
        safe_name=$(echo "$c_file" | tr '/' '_')
        o_file="objects/${safe_name%.c}.o"
        
        # Compile to .o
        gcc -Wall -Wextra -g -I"$folder/include" -I"$folder" -c "$c_file" -o "$o_file"
        
        # Check if it has a main function
        if grep -qE "(int|void)[[:space:]]*main[[:space:]]*\(" "$c_file" || grep -qE "^main[[:space:]]*\(" "$c_file" || grep -qw "main" "$c_file"; then
            main_o_files="$main_o_files $o_file"
        else
            lib_o_files="$lib_o_files $o_file"
        fi
    done
    
    # Count how many mains we have
    main_count=$(echo "$main_o_files" | wc -w)
    
    if [ "$main_count" -eq 1 ]; then
        # Only one main, name executable after the folder
        gcc $main_o_files $lib_o_files -o "out/$folder" -lm
        echo "  Created out/$folder"
    elif [ "$main_count" -gt 1 ]; then
        # Multiple mains, create an executable for each
        for m_o in $main_o_files; do
            # Extract a good name from the object filename
            # Example: objects/queue_array_main.o -> queue_array
            base_name=$(basename "$m_o" .o)
            # Remove the generic 'objects/folder_' prefix
            prog_name=${base_name#${folder}_}
            # Remove '_main' suffix if present
            prog_name=${prog_name%_main}
            if [ "$prog_name" == "$base_name" ] || [ -z "$prog_name" ]; then
                prog_name=$(basename "$m_o" .o)
            fi
            
            exec_name="out/${folder}_${prog_name}"
            gcc $m_o $lib_o_files -o "$exec_name" -lm
            echo "  Created $exec_name"
        done
    else
        echo "  No main function found in $folder"
    fi
}

folders="array singly_linked_list doubly_linked_list circular_linked_list stack infix_to_postfix string_reversal postfix_evaluation queue binary_tree"

for f in $folders; do
    if [ -d "$f" ]; then
        compile_folder "$f"
    fi
done

echo "Build complete."

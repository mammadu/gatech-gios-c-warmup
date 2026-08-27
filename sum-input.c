#include <stdio.h>

int main(int argc, char *argv[])
{
    // ensure user provides correct argument count
    if (argc != 3){
        printf("Error! Incorrect number of arguments provided (2 needed, %d provided)\n", argc - 1);
        return 1;
    }

    // open input_file for reading
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL){
        printf("Error! could not open input_file: %s\n", argv[1]);
        return 1;
    }

    // open a output_file for writing
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL){
        printf("Error! could not open output_file: %s\n", argv[2]);
        return 1;
    }

    // read the numbers into a temporary variable and sum the ints
    int sum = 0;
    int temp;
    char whitespace;
    while(fscanf(input_file, "%d%c", &temp, &whitespace) == 2){
        sum += temp;
        // if we find a newline, write to the outputfile and reset sum to 0
        if (whitespace == '\n'){
            fprintf(output_file, "%d\n", sum);
            sum = 0;
        }
    }

    fclose(input_file);
    fclose(output_file);
}

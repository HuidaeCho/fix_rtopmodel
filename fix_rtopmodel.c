#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;

    if (argc < 2) {
        printf
            ("This program fixes r.topmodel input files by converting UNIX files to DOS file format and removing newline at the end of the files.\n\n");
        printf("Usage: fix_rtopmodel file...\n");
        exit(EXIT_SUCCESS);
    }

    for (i = 1; i < argc; i++) {
        FILE *infp, *outfp;
        char outfile[1024], buf[1024];
        int first = 1;

        if (!(infp = fopen(argv[i], "r"))) {
            printf("Failed to open %s\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        sprintf(outfile, "%s.out", argv[i]);

        if (!(outfp = fopen(outfile, "w"))) {
            printf("Failed to create %s\n", outfile);
            exit(EXIT_FAILURE);
        }

        while (!feof(infp)) {
            if (first)
                first = 0;
            else
                fprintf(outfp, "\n");
            fscanf(infp, " %[^\r\n] ", buf);
            fprintf(outfp, "%s", buf);
        }

        fclose(infp);
        fclose(outfp);
    }
}

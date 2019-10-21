#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define BLOCK_SIZE 512

typedef uint8_t BYTE;

int main(void)
{

    // open input file
    FILE *inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Invalid file type.\n");
        return 1;
    }

    BYTE buffer[512];
    int imageCount = 0;

    char filename[8];
    FILE *outptr = NULL;

    while (true)
    {
        // read a block of the memory
        size_t bytesRead = fread(buffer, sizeof(BYTE), BLOCK_SIZE, inptr);

        // break out of the loop when we reach the end of the card image
        if (bytesRead == 0 && feof(inptr))
        {
            break;
        }

        // check for JPEG
        bool containsJpegHeader = buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0;

        // if we find JPEG, we must close the previous file
        if (containsJpegHeader && outptr != NULL)
        {
            fclose(outptr);
            imageCount++;
        }

        // write file
        if (containsJpegHeader)
        {
            sprintf(filename, "%03i.jpg", imageCount);
            outptr = fopen(filename, "w");
        }

        // write anytime we have an open file
        if (outptr != NULL)
        {
            fwrite(buffer, sizeof(BYTE), bytesRead, outptr);
        }
    }

    // close everything
    fclose(outptr);
    fclose(inptr);

    return 0;
}
© 2019 GitHub, Inc.
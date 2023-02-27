#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Input.h"
#include "ErrorCodes.h"
#include "Output.h"


FILE* GetFile(int* successToken)
{
#pragma warning(suppress : 4996)
    FILE* result = fopen(filePath, "r");

    if (result != NULL)
        *successToken = 0;
    else
        *successToken = LogMissingMatrixFile();

    return result;
}

void ReadDimensions(FILE* inputData, int* successToken)
{
    int internalSuccessToken;
    *successToken = 0;

    char* rowsInput = malloc(maxSubstringLength);
    char* columnsInput = malloc(maxSubstringLength);
#pragma warning(suppress : 4996)
    fscanf(inputData, "%s%s", rowsInput, columnsInput);

    rows = ConvertToInt(rowsInput, &internalSuccessToken);
    if (internalSuccessToken == invalidNumberStringToken || rows <= 0) {
        *successToken = LogInvalidInputDimensions("row");
    }

    columns = ConvertToInt(columnsInput, &internalSuccessToken);
    if (internalSuccessToken == invalidNumberStringToken || columns <= 0) {
        *successToken = LogInvalidInputDimensions("column");
    }

    free(rowsInput);
    free(columnsInput);
}

void ReadMatrix(FILE* inputData, int* successToken)
{
    *successToken = 0;
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            char numberString[maxSubstringLength];

#pragma warning(suppress : 4996)
            fscanf(inputData, "%s", &numberString);
            int converted = ConvertToInt(numberString, successToken);

            if (*successToken == invalidNumberStringToken) {
                *successToken = LogInvalidInputMatrix(row, column);
                return;
            }
            matrix[row][column] = converted;
        }
    }
}

int ConvertToInt(char string[], int* successToken)
{
    int result = 0;
    *successToken = invalidNumberStringToken;

    if (successToken == NULL)
        return result;

    *successToken = 0;
    if (strcmp(string, "0") == 0)
        return result;

    result = atoi(string);
    if (result == 0)
        *successToken = invalidNumberStringToken;

    return result;
}

int LogMissingMatrixFile()
{
    printf("Possibly matrix file is missing at %s!\n", filePath);
    return missingFileToken;
}
int LogInvalidInputDimensions(char* dimensionName)
{
    printf("Input %s is invalid!\n", dimensionName);
    return invalidDimensionsToken;
}

int LogInvalidInputMatrix(int row, int column)
{
    printf("Input matrix contains invalid value in row[%d] column[%d]!\n", row, column);
    return invalidMatrixDataToken;
}
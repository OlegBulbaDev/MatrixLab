#pragma once
#include "stdio.h"

#define filePath "C:\\Users\\Oleg\\Code\\MatrixLab\\InputData\\Matrix.txt"
#define maxSubstringLength 255

FILE* GetFile(int* successToken);
void ReadDimensions(FILE* inputData, int* successToken);
void ReadMatrix(FILE* inputData, int* successToken);
int ConvertToInt(char string[], int* successToken);

int LogMissingMatrixFile();
int LogInvalidInputDimensions(char* dimensionName);
int LogInvalidInputMatrix(int row, int column);
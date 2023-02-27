#include <stdio.h>
#include "Input.h"
#include "Output.h"
#include "ErrorCodes.h"

int main() {

    int successToken;

    FILE* inputData = GetFile(&successToken);
    if (successToken != 0)
        return successToken;

    ReadDimensions(inputData, &successToken);
    if (successToken != 0)
        return successToken;

    ReadMatrix(inputData, &successToken);
    if (successToken != 0)
        return successToken;

    OutputMatrix();

    return 0;
}



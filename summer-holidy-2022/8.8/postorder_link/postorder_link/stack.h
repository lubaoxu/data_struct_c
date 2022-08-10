#pragma once

#include "data.h"

void initializeStack(Stack* pStack);
void unInitializeStack(Stack* pStack);

void pushStack(Stack* pStack, Data* pNode);
Data* popStack(Stack* pStack);


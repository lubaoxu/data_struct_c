
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef char ADT;

struct Data {
    char cPoint;
    Data* pLeftChild;
    Data* pRightChild;
    Data* pParent;
};

Data* creatTreeNode1(char cPoint)
{
    Data* pCurrentNode = (Data*)malloc(sizeof(Data));
    pCurrentNode->pLeftChild = NULL;
    pCurrentNode->pRightChild = NULL;
    pCurrentNode->pParent = NULL;
    pCurrentNode->cPoint = cPoint;
    return pCurrentNode;
}

void creatTreeNode2(Data** ppTreeNode, char cPoint)
{
    *ppTreeNode = (Data*)malloc(sizeof(Data));
    (*ppTreeNode)->pLeftChild = NULL;
    (*ppTreeNode)->pRightChild = NULL;
    (*ppTreeNode)->pParent = NULL;
    (*ppTreeNode)->cPoint = cPoint;

}

void log(Data* arrNode[], int nLength)
{
    for (int i = 0; i < nLength; i++)
    {

        char cLeftPoint = -1;
        if (arrNode[i] != NULL && arrNode[i]->pLeftChild != NULL)
        {
            cLeftPoint = arrNode[i]->pLeftChild->cPoint;
        }

        char cRightPoint = -1;
        if (arrNode[i] != NULL && arrNode[i]->pRightChild != NULL)
        {
            cRightPoint = arrNode[i]->pRightChild->cPoint;
        }
        char cParent = -1;
        if (arrNode[i] != NULL && arrNode[i]->pParent != NULL)
        {
            cParent = arrNode[i]->pParent->cPoint;
        }

        printf("值:c\t左孩子:%c\t右孩子:%c\t父节点:%c\n", arrNode[i]->cPoint, cLeftPoint, cRightPoint, cParent);
    }
}

void preorder(Data* pNode)
{
    if(pNode==NULL)
    {
        return ;
    }
    printf("%c\n", pNode->cPoint);
    preorder(pNode->pLeftChild);
    preorder(pNode->pRightChild);
    
}

void interthem(Data* pNode)
{  
    if (pNode == NULL)
    {
        return;
    }
     preorder(pNode->pLeftChild);
     printf("%c\n", pNode->cPoint);
     preorder(pNode->pRightChild);
    
}

void postorder(Data* pNode)
{
    if (pNode == NULL)
    {
        return;
    }
    preorder(pNode->pLeftChild);
    preorder(pNode->pRightChild);
    printf("%c\n", pNode->cPoint);
}

int main()
{
    Data* pFirstNode = NULL;
    creatTreeNode2(&pFirstNode, 'A');
    Data* pSecondNode = NULL;
    creatTreeNode2(&pSecondNode, 'B');
    Data* pThirdNode = NULL;
    creatTreeNode2(&pThirdNode, 'C');
    Data* pFourthNode = NULL;
    creatTreeNode2(&pFourthNode, 'D');
    Data* pFifthNode = NULL;
    creatTreeNode2(&pFifthNode, 'E');
    Data* pSixthNode = NULL;
    creatTreeNode2(&pSixthNode, 'F');
    Data* pSeventhNode = NULL;
    creatTreeNode2(&pSeventhNode, 'G');

    pFirstNode->pLeftChild = pSecondNode;
    pSecondNode->pParent = pFirstNode;

    pFirstNode->pRightChild = pThirdNode;
    pThirdNode->pParent = pFirstNode;

    pSecondNode->pLeftChild = pFourthNode;
    pFourthNode->pParent = pSecondNode;

    pSecondNode->pRightChild = pFifthNode;
    pFifthNode->pParent = pSecondNode;

    pThirdNode->pRightChild = pSixthNode;
    pSixthNode->pParent = pThirdNode;

    pFifthNode->pRightChild = pSeventhNode;
    pSeventhNode->pParent = pFifthNode;

    Data* arrNodexx[] = { pFirstNode,pSecondNode,pThirdNode,pFourthNode,pFifthNode,pSixthNode,pSeventhNode };
    int iLength = sizeof(arrNodexx) / sizeof(arrNodexx[0]);
    log(arrNodexx, iLength);

    preorder(pFirstNode);
    printf("\n");
    interthem(pFirstNode);
    printf("\n");
    postorder(pFirstNode);
    return 0;
}

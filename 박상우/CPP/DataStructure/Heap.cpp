#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
using namespace std;

// 힙의 각 노드를 표현하는 HeapNode 구조체와,
// 힙 자체를 표현하는 Heap 구조체 두 가지 구조체를 사용.
// Heap 구조체의 Capacity필드는 힙의 용량, 즉 Nodes 배열의 크기를 나타내고
// UsedSize는 실제 배열 안에 들어 있는 큐 요소의 수를 나타냄.

typedef int ElementType;     // 이건 뭐해주는거지??

typedef struct HeapNode {
    ElementType Data;
} HeapNode;

typedef struct Heap {
    HeapNode* Nodes;
    int Capacity;
    int UsedSize;
} Heap;

Heap* HEAP_Create(int InitialSize);
void HEAP_Destroy(Heap* H);
void HEAP_Insert(Heap* H, ElementType NewData);
void HEAP_DeleteMin(Heap* H, HeapNode* Root);
int HEAP_GetParent(int Index);
int HEAP_GetLeftChild(int Index);
void HEAP_SwapNodes(Heap* H, int Index1, int Index2);
void HEAP_PrintNodes(Heap* H);

// 힙 생성
Heap* HEAP_Create(int InitialSize) {
    Heap* NewHeap = (Heap*) malloc(sizeof(Heap));
    NewHeap->Capacity = InitialSize;
    NewHeap->UsedSize = 0;
    NewHeap->Nodes = (HeapNode*) malloc(sizeof(HeapNode) * NewHeap->Capacity);
    printf("size : %d\n", sizeof(HeapNode));
    return NewHeap;
}

// 힙 소멸
void HEAP_Destroy(Heap* H) {
    free(H->Nodes);
    free(H);
}

// 힙 삽입
void HEAP_Insert(Heap* H, ElementType NewData) {
    int CurrentPosition = H->UsedSize;
    int ParentPosition = HEAP_GetParent(CurrentPosition);

    // UsedSize가 Capacity에 도달하면 Capacity를 두 배로 늘린다.
    if (H->UsedSize == H->Capacity) {
        H->Capacity *= 2;
        // realloc 알아보기..
        H->Nodes = (HeapNode*) realloc(H->Nodes, sizeof(HeapNode)*H->Capacity);
    }

    H->Nodes[CurrentPosition].Data = NewData;
    
    // 후속 처리
    while (CurrentPosition > 0
            && H->Nodes[CurrentPosition].Data < H->Nodes[ParentPosition].Data) 
    {
        HEAP_SwapNodes(H, CurrentPosition, ParentPosition);
        CurrentPosition = ParentPosition;
        ParentPosition = HEAP_GetParent(CurrentPosition);
    }
    H->UsedSize++;
}

// Node Swap
void HEAP_SwapNodes(Heap* H, int Index1, int Index2) {
    int CopySize = sizeof(HeapNode);
    HeapNode* Temp = (HeapNode*) malloc(CopySize);

    memcpy(Temp,              &H->Nodes[Index1], CopySize);
    memcpy(&H->Nodes[Index1], &H->Nodes[Index2], CopySize);
    memcpy(&H->Nodes[Index2], Temp,              CopySize);

    free(Temp);
}

// Delete Min
void HEAP_DeleteMin(Heap* H, HeapNode* Root) {
    int ParentPosition = 0;
    int LeftPosition = 0;
    int RightPosition = 0;

    memcpy(Root, &H->Nodes[0], sizeof(HeapNode));
    memcpy(&H->Nodes[0], 0, sizeof(HeapNode));

    H->UsedSize--;
    HEAP_SwapNodes(H, 0, H->UsedSize);

    LeftPosition = HEAP_GetLeftChild(0);
    RightPosition = LeftPosition + 1;

    while (1) {
        int SelectedChild = 0;
        if (LeftPosition >= H->UsedSize) break;
        if (RightPosition >= H->UsedSize) {
            SelectedChild = LeftPosition;
        }
        else {
            if (H->Nodes[LeftPosition].Data > H->Nodes[RightPosition].Data)
                SelectedChild = RightPosition;
            else 
                SelectedChild = LeftPosition;
        }
        if (H->Nodes[SelectedChild].Data < H->Nodes[ParentPosition].Data) {
            HEAP_SwapNodes(H, ParentPosition, SelectedChild);
            ParentPosition = SelectedChild;
        }
        else
            break;
        
        LeftPosition = HEAP_GetLeftChild(ParentPosition);
        RightPosition = LeftPosition + 1;       
    }

    if (H->UsedSize < (H->Capacity / 2)) {
        H->Capacity /= 2;
        H->Nodes = (HeapNode*)realloc(H->Nodes, sizeof(HeapNode) * H->Capacity);
    }
}

// 부모 인덱스 찾기.
int HEAP_GetParent(int Index) {
    return (int) ((Index - 1) / 2);
}

// 왼쪽 자식의 인덱스 찾기
int HEAP_GetLeftChild(int Index) {
    return (2 * Index) + 1;
}

// 노드 출력하기
void HEAP_PrintNodes(Heap* H) {
    int i;
    for (i = 0; i < H->UsedSize; i++) {
        printf("%d ", H->Nodes[i].Data);
    }
    printf("\n");
}

int main() {
    Heap* H = HEAP_Create(3);
    HeapNode MinNode;

    HEAP_Insert(H, 12);
    HEAP_Insert(H, 87);
    HEAP_Insert(H, 111);
    HEAP_Insert(H, 34);
    HEAP_Insert(H, 16);
    HEAP_Insert(H, 75);
    HEAP_PrintNodes(H);

    MinNode = H->Nodes[0];  // 이거 어케해야하지..ㅜㅜ
    HEAP_DeleteMin(H, &MinNode);
    HEAP_PrintNodes(H);

    return 0;
}

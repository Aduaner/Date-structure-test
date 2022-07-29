#include <iostream>
using namespace std;
typedef int ElemType;

namespace Sequence {
    typedef struct LinkNode {
        ElemType data;
        struct LinkNode *next;
    } LinkNode;//定义节点
    typedef struct {
        LinkNode *front,*rear;
    } LinkQueue;//定义队列首位指针
}

#include "NodeAVL.hpp"

NodeAVL::NodeAVL(Queue* vr, NodeAVL *sl, NodeAVL *sg) {
    data = vr->sumQueue();
    line = vr;
    left = sl;
    right = sg;
    height = 0;
}

NodeAVL::NodeAVL(Queue* vr, NodeAVL *sl) {
    data = vr->sumQueue();
    line = vr;
    left = sl;
    right = 0;
    height = 0;
}

NodeAVL::NodeAVL(Queue* vr) {
    data = vr->sumQueue();
    line = vr;
    left = 0;
    right = 0;
    height = 0;
}

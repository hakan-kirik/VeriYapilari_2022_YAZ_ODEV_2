
#include "Avl.hpp"

NodeAVL* AVL::SearchAndAdd(NodeAVL *subNode, int item, Queue *items) {

    if (subNode == NULL) subNode = new NodeAVL(items);
    else if (item < subNode->data) {
        subNode->left = SearchAndAdd(subNode->left, item, items);

        if (Height(subNode->left) == Height(subNode->right) + 2) {
            if (item < subNode->left->data)

                subNode = SwapWithLeftChild(subNode);
            else {

                subNode->left = SwapWithRightChild(subNode->left);
                subNode = SwapWithLeftChild(subNode);
            }
        }
    } else if (item > subNode->data) {
        subNode->right = SearchAndAdd(subNode->right, item, items);

        if (Height(subNode->right) == Height(subNode->left) + 2) {
            if (item > subNode->right->data)

                subNode = SwapWithRightChild(subNode);
            else {

                subNode->right = SwapWithLeftChild(subNode->right);
                subNode = SwapWithRightChild(subNode);
            }
        }
    } else;

    subNode->height = Height(subNode);
    return subNode;
}

NodeAVL* AVL::SwapWithLeftChild(NodeAVL *subNode) {


    NodeAVL *tmp = subNode->left;
    subNode->left = tmp->right;
    tmp->right = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->left), subNode->height);

    if (!subNode->line->isEmpty()) {
        cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->line->peekMax() << " sayisi silinmistir" << endl;
        subNode->line->dequeueMax();
    }
    postorderMaxDel(subNode->right);
    if (!tmp->line->isEmpty()) {
        cout << tmp->data << " nolu dugum yukari ciktigi icin en kucuk " << tmp->line->peek() << " sayisi silinmistir" << endl;
        tmp->line->dequeue();
    }
    postorderDel(tmp->left);
    return tmp;
}

NodeAVL* AVL::SwapWithRightChild(NodeAVL *subNode) {

    NodeAVL *tmp = subNode->right;
    subNode->right = tmp->left;
    tmp->left = subNode;

    subNode->height = Height(subNode);
    tmp->height = 1 + max(Height(tmp->right), subNode->height);
    if (!subNode->line->isEmpty()) {
        cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->line->peekMax() << " sayisi silinmistir" << endl;
        subNode->line->dequeueMax();
    }
    postorderMaxDel(subNode->left);
    if (!tmp->line->isEmpty()) {
        cout << tmp->data << " nolu dugum yukari ciktigi icin en kucuk " << tmp->line->peek() << " sayisi silinmistir" << endl;
        tmp->line->dequeue();
    }
    postorderDel(tmp->right);
    return tmp;
}

bool AVL::DeleteNode(NodeAVL *&subNode) {
    NodeAVL *delNode = subNode;

    if (subNode->right == NULL) subNode = subNode->left;
    else if (subNode->left == NULL) subNode = subNode->right;
    else {
        delNode = subNode->left;
        NodeAVL *parentNode = subNode;
        while (delNode->right != NULL) {
            parentNode = delNode;
            delNode = delNode->right;
        }
        subNode->data = delNode->data;
        if (parentNode == subNode) subNode->left = delNode->left;
        else parentNode->right = delNode->left;
    }
    delete delNode;
    return true;
}

void AVL::postorderMaxDel(NodeAVL *subNode) {

    if (subNode != NULL) {

        postorderMaxDel(subNode->left);
        postorderMaxDel(subNode->right);
        if (!subNode->line->isEmpty()) {
            cout << subNode->data << " nolu dugum asagi indigi icin en buyuk " << subNode->line->peekMax() << " sayisi silinmistir" << endl;
            subNode->line->dequeueMax();
        }

    }
}

void AVL::postorderDel(NodeAVL *subNode) {
    if (subNode != NULL) {

        postorderDel(subNode->left);
        postorderDel(subNode->right);
        if (!subNode->line->isEmpty()) {
            cout << subNode->data << " nolu dugum yukari ciktigi icin en kucuk " << subNode->line->peek() << " sayisi silinmistir" << endl;
            subNode->line->dequeue();
        }
    }
}

void AVL::preorder(NodeAVL *subNode) {
    if (subNode != NULL) {
        cout << subNode->data << ": ";
        while (!subNode->line->isEmpty()) {

            int number = subNode->line->peek();
            std::cout << number << " ";
            subNode->line->dequeue();
        }
        cout << endl;
        preorder(subNode->left);
        preorder(subNode->right);
    }
}

int AVL::Height(NodeAVL *subNode) {
    if (subNode == NULL) return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}

AVL::AVL() {
    root = NULL;
}

bool AVL::isEmpty()const {
    return root == NULL;
}

void AVL::Add(Queue* item) {
    int num = item->sumQueue();
    root = SearchAndAdd(root, num, item);
}

void AVL::preorder() {
    preorder(root);
}

int AVL::Height() {
    return Height(root);
}

void AVL::Clear() {
    while (!isEmpty()) DeleteNode(root);
}

AVL::~AVL() {
    Clear();
}

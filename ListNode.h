#pragma once

class ListNode{
public:
    int id;
    int x;
    int y;
    int nextWeight;
    ListNode * next;
    ListNode(int idIN, int xIN, int yIN): id(idIN), x(xIN), y(yIN), nextWeight(0), next(nullptr) { }
};

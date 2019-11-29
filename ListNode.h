#pragma once

class ListNode{
public:
    int id;
    int weight;
    int x, y;
    ListNode* next;
    ListNode(int x, int y){
        this->x = x;
        this->y = y;
    }
};

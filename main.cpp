#include "singlelink.hpp"
#include <string>

class monopoly_board : public node_container::single::circular_list<std::string> {

    node_container::node<std::string>* current_node = nullptr;

public:

    monopoly_board () : current_node(get_head()) {}

//    monopoly_board () : node_container::single::circular_list<std::string>() {
//
//        current_node = nullptr;
//    }

    void step() {

        if (get_head() == nullptr) {throw std::runtime_error("head is null");}
        if (current_node == nullptr) current_node = get_head();
        current_node = current_node->next;
    }

    std::string get_current_node () {if (current_node == nullptr) {throw std::runtime_error("currrent node null");}
        return current_node->data;}

};


int main () {

    monopoly_board board;

    board.add("go");
    board.add("Mediteranean Avenue");
    board.add("Community Chest");
    board.add("Baltic Avenue");
    board.add("Income Tax");

    board.step();
    board.step();

    std::cout << board.get_current_node() << std::endl;

    board.step();
    board.step();

    std::cout << board.get_current_node() << std::endl;

    for(int i = 0; i < 37; i++) {
        board.step();
    }

    std::cout << board.get_current_node() << std::endl;

}
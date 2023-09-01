#include <bits/stdc++.h>


struct link {
	char info;
	struct link* next;
};

struct link* start = NULL;


struct link* create_header_list(char data)
{
	struct link *new_node, *node;
	new_node = (struct link*)malloc(sizeof(struct link));
	new_node->info = data;
	new_node->next = NULL;


	if (start == NULL) {


		start = (struct link*)malloc(sizeof(struct link));
		start->next = new_node;
	}
	else {
		
		node = start;
		while (node->next != NULL) {
			node = node->next;
		}
		node->next = new_node;
	}
	return start;
}


struct link* display()
{
	struct link* node;
	node = start;
	node = node->next;


	while (node != NULL) {

		
		std::cout << node->info << " ";
		node = node->next;
	}
	std::cout << std::endl;

	
	return start;
}


int main()
{
    int numElements;
    std::cin >> numElements;
    for (int i = 0; i < numElements; i++) {
        char value;
        std::cin >> value;
        create_header_list(value);
    }
	display();

	return 0;
}






//Sushant








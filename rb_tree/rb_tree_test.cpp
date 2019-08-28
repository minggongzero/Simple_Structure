#include <iostream>
#include <algorithm>
#include "rb_tree.h"

int main()
{
	rb_tree<int> rb;
	rb_tree_node<int> p0, p1, p2, p3, p4, p5, p6, p7, p8;
	p0.val = 11;
	p0.leftchild = &p1;
	p0.rightchild = &p2;
	p0.parent = rb.nil;
	p0.color = BLACK;
		
	p1.val = 2;
	p1.leftchild = &p3;
	p1.rightchild = &p4;
	p1.parent = &p0;
	p1.color = RED;

	p2.val = 14;
	p2.leftchild = rb.nil;
	p2.rightchild = &p5;
	p2.parent = &p0;
	p2.color = BLACK;

	p3.val = 1;
	p3.leftchild = rb.nil;
	p3.rightchild = rb.nil;
	p3.parent = &p1;
	p3.color = BLACK;
	
	p4.val = 7;
	p4.leftchild = &p6;
	p4.rightchild = &p7;
	p4.parent = &p1;
	p4.color = BLACK;

	p5.val = 15;
	p5.leftchild = rb.nil;
	p5.rightchild = rb.nil;
	p5.parent = &p2;
	p5.color = RED;

	p6.val = 5;
	p6.leftchild = rb.nil;
	p6.rightchild = rb.nil;
	p6.parent = &p4;
	p6.color = RED;

	p7.val = 8;
	p7.leftchild = rb.nil;
	p7.rightchild = rb.nil;
	p7.parent = &p4;
	p7.color = RED;

	p8.val = 4;
	p8.leftchild = rb.nil;
	p8.rightchild = rb.nil;
	p8.parent = rb.nil;
	
	rb.root = &p0;

	rb.output();
/*
	rb.insert(&p8);
	rb.output();
*/
	rb_tree_node<int> p12, p13, p14, p16;
	p12.val = 12;
	p12.leftchild = rb.nil;
	p12.rightchild = rb.nil;
	p12.parent = &p2;
	p12.color = BLACK;
	p2.leftchild = &p12;

	p13.val = 13;
	p13.leftchild = rb.nil;
	p13.rightchild = rb.nil;
	p13.parent = &p12;
	p13.color = BLACK;
	p12.rightchild = &p13;

	p14.val = 14;
	p14.leftchild = rb.nil;
	p14.rightchild = rb.nil;
	p14.parent = &p5;
	p14.color = BLACK;
	p5.leftchild = &p14;

	p16.val = 16;
	p16.leftchild = rb.nil;
	p16.rightchild = rb.nil;
	p16.parent = &p5;
	p16.color = BLACK;
	p5.rightchild = &p16;

	rb.output();
	rb.remove(&p0);
	rb.output();
	return 0;
}

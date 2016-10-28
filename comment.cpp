#include "comment.h"

Comment::Comment(Base* child) {
	commented = child;
}

Comment::execute() {
	return 0;
}
#include "comment.h"

Comment::Comment(Base* child) {
	commented = child;
}

int Comment::execute() {
	return 0;
}

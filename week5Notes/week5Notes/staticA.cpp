#include <iostream>
static std::ostream& display(std::ostream& os) {
	os << "Hello from World A" << std::endl;
	return os;
}
void otherworldlyportal();
int main() {
	display(std::cout);
	otherworldlyportal();
}
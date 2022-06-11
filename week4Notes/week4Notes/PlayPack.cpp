#include "Playdoh.h"
#include "PlaydohPack.h"
Playdoh::PlaydohPack() {
}
PlaydohPack::PlaydohPack(const char* nm, int dc, const char* dohs[]) : name(nm), dohCount(dc) {
	if (dohCount > 0) {
		playdohs = new Playdoh[dohCount];
		for (int i = 0; i < dohCount; i++) {
			playdohs[i].setColour(dohs[i]);
			playdohs[i].setWeight(rand() % 10);
		}
	}
}
PlaydohPack::PlaydohPack(const PlaydohPack& src) {
	*this = src;
}
PlaydohPack& PlaydohPack::operator=(const PlaydohPack& src) {
	if (this != &src) {
		delete[] playdohs;
		playdohs = nullptr;
		name = src.name;
		dohCount = src.dohCount;
		if (src.playdohs && dohCount > 0) {
			playdohs = new Playdoh[dohCount];
			for (int i = 0; i < dohCount; i++) {
				playdohs[i] = src.playdohs[i]
			}
		}
		return *this;
	}
}
PlaydohPack::~PlaydohPack() {
	delete[] playdohs;
}
stdLLostream& operator<<(std::ostream& os, const PlaydohPack& p) {
	return p.display(os);
}
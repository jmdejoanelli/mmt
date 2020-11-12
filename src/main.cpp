#include "Magic.hpp"

#include <cstdio>

int main(int argc, char** argv) {
	if (argc != 2)
		return 1;

	std::string arg(argv[1]);

	Magic magic;
	auto  mimeType = magic.getMime(arg);

	return 0;
}

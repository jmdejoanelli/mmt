#include "Magic.hpp"

#include <cstdio>
#include <filesystem>

int main(int argc, char** argv) {
	if (argc != 2)
		return 1;

	std::string arg(argv[1]);

	Magic magic;

	for (const auto& f: std::filesystem::recursive_directory_iterator(arg)) {
		if (f.is_regular_file()) {
			auto mimeType = magic.getMime(f.path());
			/* printf("%s\n", f.path().c_str()); */
		}
	}

	return 0;
}

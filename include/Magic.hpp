#pragma once

#include <filesystem>
#include <magic.h>
#include <optional>
#include <string>

struct MimeType {
	std::string type;
	std::string subtype;
};

class Magic {
public:
	Magic();
	~Magic();
	Magic(const Magic& rhs) = delete;
	Magic& operator=(const Magic& rhs) = delete;
	Magic(Magic&& rhs);
	Magic& operator=(Magic&& rhs);

	std::optional<MimeType> getMime(const std::filesystem::path& file);

private:
	magic_t m_magic;
};

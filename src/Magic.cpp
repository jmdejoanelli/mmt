#include "Magic.hpp"

#include <cstdio>
#include <utility>

namespace {

std::optional<MimeType> splitMime(const std::string& mimeString) {
	const std::string delimiter("/");
	const auto        delimiterLocation = mimeString.find(delimiter);

	// Check if delimiter is not found in the string.
	if (delimiterLocation == std::string::npos)
		return std::nullopt;

	// Check if delimeter is at the beginning of the string.
	if (delimiterLocation == 0)
		return std::nullopt;

	// Check if delimeter is at the end of the string.
	if (delimiterLocation == mimeString.size() - 1)
		return std::nullopt;

	MimeType mt{
		mimeString.substr(0, delimiterLocation),
		mimeString.substr(delimiterLocation + 1, mimeString.size()),
	};

	return std::make_optional<MimeType>(mt);
}

} // namespace

Magic::Magic()
	: m_magic(::magic_open(MAGIC_MIME_TYPE)) {
	::magic_load(m_magic, NULL);
}

Magic::~Magic() {
	::magic_close(m_magic);
}

Magic::Magic(Magic&& rhs)
	: m_magic(std::exchange(rhs.m_magic, nullptr)) {
}

Magic& Magic::operator=(Magic&& rhs) {
	m_magic = std::exchange(rhs.m_magic, nullptr);
	return *this;
}

std::optional<MimeType> Magic::getMime(const std::filesystem::path& path) {
	auto abspath = std::filesystem::absolute(path);

	if (std::filesystem::exists(abspath))
		abspath = std::filesystem::canonical(abspath);

	auto mimeType(splitMime(::magic_file(m_magic, abspath.c_str())));

	if (mimeType)
		printf("%s: %s::%s\n", abspath.c_str(), mimeType->type.c_str(), mimeType->subtype.c_str());

	splitMime("type/subtype");
	splitMime("typesubtype");
	splitMime("/typesubtype");
	splitMime("typesubtype/");

	return mimeType;
}

#ifndef HPP_LEXICALCAST
#define HPP_LEXICALCAST

#include <sstream>

template <typename T>
T fromString(const std::string s) {
	std::istringstream ss(s);
	T t;
	ss >> t;
	return t;
}

// Specialization for unsigned char to treat it as numeric value, not ASCII character
template <>
inline unsigned char fromString<unsigned char>(const std::string s) {
	std::istringstream ss(s);
	unsigned int temp;
	ss >> temp;
	return static_cast<unsigned char>(temp);
}

template <typename T>
std::string toString(const T & t) {
	std::ostringstream ss;
	ss << t;
	return ss.str();
}

#endif /* HPP_LEXICALCAST */
/**********************************************************
 * Name: Xuewei Sheng
 * Student ID: 061745121
 * Seneca email: xsheng3@myseneca.ca
 * Section: NFF
 **********************************************************/
#include "HtmlText.h"
#include"cstring.h"
namespace sdds {
	void HtmlText::setTitle(const char* title) {
		if (m_title != nullptr)
		{
			delete[] m_title;
			m_title = nullptr;
		}
		if (title)
		{
			int len = strLen(title);
			m_title = new char[len + 1];
			strCpy(m_title, title);
		}
		else m_title = nullptr;
	}
	HtmlText::HtmlText(const char* filename, const char* title) :Text(filename), m_title(nullptr) {
		setTitle(title);
	}

	HtmlText::HtmlText(const HtmlText& src):Text(src) {
		m_title = nullptr;
		*this = src;
	}

	HtmlText& HtmlText::operator=(const HtmlText& src) {
		if (this != &src)
		{
			(Text&)*this = src;
			if (m_title != nullptr)
			{
				delete[] m_title;
				m_title = nullptr;
			}
			setTitle(src.m_title);
		}
		return *this;
	}

	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}

	void HtmlText::write(std::ostream& os)const {
		bool MS = false;
		os << "<html><head><title>";
		if (m_title)
		{
			os << m_title << "</title></head>" << endl << "<body>" << endl;
		}
		else
		{
			os << "No Title" << " < / title > < / head>" << endl << "<body>" << endl;
		}
		if (m_title)
		{
			os << "<h1>" << m_title << "</h1>\n";
		}

		const HtmlText& T = *this;
		int i = 0;
		while (T[i] != '\0')
		{
			switch (T[i])
			{
			case ' ':
				if (MS)
				{
					os << "&nbsp;";
				}
				else
				{
					MS = true;
					os << ' ';
				}
				break;
			case '<':
				os << "&lt;";
				MS = false;
				break;
			case '>':
				os << "&gt;";
				MS = false;
				break;
			case '\n':
				os << "<br />\n";
				MS = false;
				break;
			default:
				os << T[i];
				MS = false;
			}

			i++;
		}
		os << "</body>\n</html>";
	}
}
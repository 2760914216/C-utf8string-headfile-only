#pragma once

#include <bits/stdc++.h>

struct utf8char
{
	char c[8];
	utf8char() = default;
	utf8char(const char* ic)
	{
		for (int i = 0; i < 8; i++)
		{
			if (*ic == '\0')
			{
				c[i] = '\0';
				break;
			}
			c[i] = *ic;
			ic++;
		}
		c[7] = '\0';
	};
	~utf8char() = default;
	const char* c_str()const noexcept
	{
		return c;
	}
};

class utf8string
{
private:
	std::list<utf8char> m_str;
	using __list = std::list<utf8char>;
	using __liter = std::list<utf8char>::iterator;
	using __cliter = std::list<utf8char>::const_iterator;
	using __rliter = std::list<utf8char>::reverse_iterator;
	using __crliter = std::list<utf8char>::const_reverse_iterator;
	using size_type = std::list<utf8char>::size_type;
	using value_type = char*;
	using reference = char*;
	using pointer = char*;
public:
	//iterator
	class iterator
	{
	private:
		std::list<utf8char>::iterator m_iter;
	public:
		iterator() = default;
		~iterator() = default;
		iterator(const __liter& iter) noexcept
		{
			m_iter = iter;
		};
		iterator(__liter&& iter) noexcept
		{
			m_iter = std::move(iter);
		};
		iterator(const iterator& iter) noexcept
		{
			m_iter = iter.m_iter;
		};
		iterator(iterator&& iter) noexcept
		{
			m_iter = std::move(iter.m_iter);
		};
		inline reference operator*()const noexcept
		{
			return m_iter->c;
		}
		inline iterator operator++() noexcept
		{
			++m_iter;
			return *this;
		}
		inline iterator operator++(int) noexcept
		{
			++m_iter;
			return *this;
		}
		inline iterator operator--() noexcept
		{
			--m_iter;
			return *this;
		}
		inline iterator operator--(int) noexcept
		{
			--m_iter;
			return *this;
		}
		inline iterator operator+(size_type n) noexcept
		{
			return operator+=(n);
		}
		inline iterator operator-(size_type n) noexcept
		{
			return operator-=(n);
		}
		inline iterator operator+=(size_type n) noexcept
		{
			for (size_type i = 0; i < n; i++)
			{
				m_iter++;
			}
			return *this;
		}
		inline iterator operator-=(size_type n) noexcept
		{
			for (size_type i = 0; i < n; i++)
			{
				m_iter--;
			}
			return *this;
		}
		inline bool operator!=(const iterator& iter)const noexcept
		{
			return !(m_iter == iter.m_iter);
		}
		inline bool operator==(const iterator& iter)const noexcept
		{
			return m_iter == iter.m_iter;
		}
		inline iterator operator=(const iterator& iter) noexcept
		{
			m_iter = iter.m_iter;
			return *this;
		}
		inline iterator operator=(iterator&& iter) noexcept
		{
			m_iter = std::move(iter.m_iter);
			return *this;
		}
		//you should not use this function
		inline utf8char __Get_utf8char()const noexcept
		{
			return *m_iter;
		}
		//you should not use this function
		inline __liter __Get_m_iter()const noexcept
		{
			return m_iter;
		}
	};
	//const_iterator
	class const_iterator
	{
	private:
		__cliter m_citer;
	public:
		const_iterator() = default;
		~const_iterator() = default;
		const_iterator(const __cliter& iter) noexcept
		{
			m_citer = iter;
		};
		const_iterator(__cliter&& iter) noexcept
		{
			m_citer = std::move(iter);
		};
		const_iterator(const const_iterator& iter) noexcept
		{
			m_citer = iter.m_citer;
		};
		const_iterator(const_iterator&& iter) noexcept
		{
			m_citer = std::move(iter.m_citer);
		};
		inline reference const operator*()const noexcept
		{
			return (reference const)m_citer->c;
		}
		inline const_iterator operator++() noexcept
		{
			++m_citer;
			return *this;
		}
		inline const_iterator operator++(int) noexcept
		{
			++m_citer;
			return *this;
		}
		inline const_iterator operator--() noexcept
		{
			--m_citer;
			return *this;
		}
		inline const_iterator operator--(int) noexcept
		{
			--m_citer;
			return *this;
		}
		inline const_iterator operator+(size_type n) noexcept
		{
			return operator+=(n);
		}
		inline const_iterator operator-(size_type n) noexcept
		{
			return operator-=(n);
		}
		inline const_iterator operator+=(size_type n) noexcept
		{
			for (size_type i = 0; i < n; i++)
			{
				++m_citer;
			}
			return *this;
		}
		inline const_iterator operator-=(size_type n) noexcept
		{
			for (size_type i = 0; i < n; i++)
			{
				--m_citer;
			}
			return *this;
		}
		inline bool operator!=(const const_iterator& iter)const noexcept
		{
			return !(m_citer == iter.m_citer);
		}
		inline bool operator==(const const_iterator& iter)const noexcept
		{
			return m_citer == iter.m_citer;
		}
		inline const_iterator operator=(const const_iterator& iter) noexcept
		{
			m_citer = iter.m_citer;
			return *this;
		}
		inline const_iterator operator=(const_iterator&& iter) noexcept
		{
			m_citer = std::move(iter.m_citer);
			return *this;
		}
		//you should not use this function
		inline utf8char __Get_utf8char()const noexcept
		{
			return *m_citer;
		}
		//you should not use this function
		inline __cliter __Get_m_iter()const noexcept
		{
			return m_citer;
		}
	};
	//reverse_iterator
	class reverse_iterator
	{
	private:
		iterator current;
	public:
		reverse_iterator() = default;
		~reverse_iterator() = default;
		reverse_iterator(const __rliter& iter)
		{
			current = iter._Get_current();
		}
		reverse_iterator(__rliter&& iter)
		{
			current = iter._Get_current();
		}
		reverse_iterator(const reverse_iterator& iter) noexcept
		{
			current = iter.current;
		};
		reverse_iterator(reverse_iterator&& iter) noexcept
		{
			current = std::move(iter.current);
		};
		inline reference operator*()const noexcept
		{
			return *current;
		}
		inline reverse_iterator operator++() noexcept
		{
			current--;
			return *this;
		}
		inline reverse_iterator operator++(int) noexcept
		{
			current--;
			return *this;
		}
		inline reverse_iterator operator--() noexcept
		{
			current++;
			return *this;
		}
		inline reverse_iterator operator--(int) noexcept
		{
			current++;
			return *this;
		}
		inline reverse_iterator operator+(size_type n) noexcept
		{
			return operator+=(n);
		}
		inline reverse_iterator operator-(size_type n) noexcept
		{
			return operator-=(n);
		}
		inline reverse_iterator operator+=(size_type n) noexcept
		{
			current -= n;
			return *this;
		}
		inline reverse_iterator operator-=(size_type n) noexcept
		{
			current += n;
			return *this;
		}
		inline bool operator!=(const reverse_iterator& iter)const noexcept
		{
			return !(current == iter.current);
		}
		inline bool operator==(const reverse_iterator& iter)const noexcept
		{
			return current == iter.current;
		}
		inline reverse_iterator operator=(const reverse_iterator& iter) noexcept
		{
			current = iter.current;
			return *this;
		}
		inline reverse_iterator operator=(reverse_iterator&& iter) noexcept
		{
			current = std::move(iter.current);
			return *this;
		}
		iterator _Get_current() const noexcept
		{
			return current;
		}
		//you should not use this function
		inline utf8char __Get_utf8char()const noexcept
		{
			return current.__Get_utf8char();
		}
		//you should not use this function
		inline __cliter __Get_m_iter()const noexcept
		{
			return current.__Get_m_iter();
		}
	};
	//const_reverse_iterator
	class const_reverse_iterator
	{
	private:
		const_iterator current;
	public:
		const_reverse_iterator() = default;
		~const_reverse_iterator() = default;
		const_reverse_iterator(const __crliter& iter)
		{
			current = iter._Get_current();
		}
		const_reverse_iterator(__crliter&& iter)
		{
			current = iter._Get_current();
		}
		const_reverse_iterator(const const_reverse_iterator& iter) noexcept
		{
			current = iter.current;
		};
		const_reverse_iterator(const_reverse_iterator&& iter) noexcept
		{
			current = std::move(iter.current);
		}
		inline reference const operator*()const noexcept
		{
			return *current;
		};
		inline const_reverse_iterator operator++() noexcept
		{
			current--;
			return *this;
		}
		inline const_reverse_iterator operator++(int) noexcept
		{
			current--;
			return *this;
		}
		inline const_reverse_iterator operator--() noexcept
		{
			current++;
			return *this;
		}
		inline const_reverse_iterator operator--(int) noexcept
		{
			current++;
			return *this;
		}
		inline const_reverse_iterator operator+(size_type n) noexcept
		{
			return operator+=(n);
		}
		inline const_reverse_iterator operator-(size_type n) noexcept
		{
			return operator-=(n);
		}
		inline const_reverse_iterator operator+=(size_type n) noexcept
		{
			current -= n;
			return *this;
		}
		inline const_reverse_iterator operator-=(size_type n) noexcept
		{
			current += n;
			return *this;
		}
		inline bool operator!=(const const_reverse_iterator& iter)const noexcept
		{
			return !(current == iter.current);
		}
		inline bool operator==(const const_reverse_iterator& iter)const noexcept
		{
			return current == iter.current;
		}
		inline const_reverse_iterator operator=(const const_reverse_iterator& iter) noexcept
		{
			current = iter.current;
			return *this;
		}
		inline const_reverse_iterator operator=(const_reverse_iterator&& iter) noexcept
		{
			current = std::move(iter.current);
			return *this;
		}
		const_iterator _Get_current() const noexcept
		{
			return current;
		}
		//you should not use this function
		inline utf8char __Get_utf8char()const noexcept
		{
			return current.__Get_utf8char();
		}
		//you should not use this function
		inline __cliter __Get_m_iter()const noexcept
		{
			return current.__Get_m_iter();
		}
	};
	inline iterator begin() noexcept
	{
		return iterator(m_str.begin());
	}
	inline const_iterator cbegin()const noexcept
	{
		return const_iterator(m_str.cbegin());
	}
	inline reverse_iterator rbegin() noexcept
	{
		return reverse_iterator(m_str.rbegin());
	}
	inline const_reverse_iterator crbegin()const noexcept
	{
		return const_reverse_iterator(m_str.crbegin());
	}
	inline iterator end() noexcept
	{
		return iterator(m_str.end());
	}
	inline const_iterator cend()const noexcept
	{
		return const_iterator(m_str.cend());
	}
	inline reverse_iterator rend() noexcept
	{
		return reverse_iterator(m_str.rend());
	}
	inline const_reverse_iterator crend()const noexcept
	{
		return const_reverse_iterator(m_str.crend());
	}
	utf8string() = default;
	~utf8string() = default;
	utf8string(const utf8string& str) = default;
	utf8string(utf8string&& str) = default;
	template<typename InputIterator>
	utf8string(InputIterator first, InputIterator last)
	{
		this->assign(first, last);
	};
	//-1 means all
	utf8string(const utf8string& str, size_type pos, size_type len = -1)
	{
		this->assign(str, pos, len);
	};
	utf8string(const char* str)
	{
		this->assign(str);
	};
	//-1 means all
	utf8string(const char* str, size_type pos, size_type len = -1)
	{
		this->assign(str, pos, len);
	};
	inline reference front() noexcept
	{
		return *begin();
	};
	inline reference front()const noexcept
	{
		return *cbegin();
	};
	inline reference back() noexcept
	{
		return *(end() - 1);
	};
	inline reference back()const noexcept
	{
		return *(cend() - 1);
	};
	inline bool empty() const noexcept
	{
		return m_str.empty();
	};
	inline size_type size() const noexcept
	{
		return m_str.size();
	};
	inline void clear() noexcept
	{
		m_str.clear();
		return;
	};
	utf8string& append(const utf8string& instr)
	{
		for (auto iter = instr.cbegin(); iter != instr.cend(); iter++)
		{
			m_str.push_back(iter.__Get_utf8char());
		}
		return *this;
	};
	inline utf8string& append(utf8string&& instr)
	{
		return append(std::move(instr));
	};
	//-1 means all
	utf8string& append(const utf8string& instr, size_type pos, size_type len = -1)
	{
		if (len == -1)
		{
			for (auto iter = instr.cbegin() + pos; iter != instr.cend(); iter++)
			{
				m_str.push_back(iter.__Get_utf8char());
			}
		}
		auto iter = instr.cbegin() + pos;
		//to prevent len is out of range
		while (iter != instr.cend() && len > 0)
		{
			m_str.push_back(iter.__Get_utf8char());
			iter++;
			len--;
		}
		return *this;
	};
	//-1 means all
	inline utf8string& append(utf8string&& instr, size_type pos, size_type len = -1)
	{
		return append(std::move(instr), pos, len);
	};
	utf8string& append(const char* instr)
	{
		while (*instr != '\0')
		{
			if (((*instr) & (1 << 7)) == 0)
			{
				utf8char c8;
				c8.c[0] = *instr;
				c8.c[1] = '\0';
				this->push_back(c8.c);
				instr++;
			}
			else
			{
				int u8clen = 0;
				for (int i = 7; i >= 0; i--)
				{
					if (((*instr) & (1 << i)) == 0)
					{
						break;
					}
					u8clen++;
				}
				utf8char c8;
				for (int i = 0; i < u8clen; i++)
				{
					c8.c[i] = *instr;
					instr++;
				}
				c8.c[u8clen] = '\0';
				this->push_back(c8.c);
			}
		}
		return *this;
	};
	//len is the length of chars in instr, not the length of utf8characters in instr and -1 means all
	utf8string& append(const char* instr, size_type pos, size_type len = -1)
	{
		instr = instr + pos;
		if (len == -1)
		{
			return append(instr);
		}
		while (*instr != '\0' && len > 0)
		{
			if (((*instr) & (1 << 7)) == 0)
			{
				utf8char c8;
				c8.c[0] = *instr;
				c8.c[1] = '\0';
				this->push_back(c8.c);
				instr++;
				len--;
			}
			else
			{
				int u8clen = 0;
				for (int i = 7; i >= 0; i--)
				{
					if (((*instr) & (1 << i)) == 0)
					{
						break;
					}
					u8clen++;
				}
				utf8char c8;
				for (int i = 0; i < u8clen; i++)
				{
					c8.c[i] = *instr;
					instr++;
					len--;
				}
				c8.c[u8clen] = '\0';
				this->push_back(c8.c);
			}
		}
		return *this;
	};
	//value must be a valid utf8character
	utf8string& append(size_type count, const char* value)
	{
		for (size_type i = 0; i < count; i++)
		{
			this->push_back(value);
		}
		return *this;
	};
	template<typename InputIterator>
	utf8string& append(InputIterator first, InputIterator last)
	{
		for (auto iter = first; iter != last; iter++)
		{
			m_str.push_back(iter.__Get_utf8char());
		}
		return *this;
	};

	inline utf8string& assign(const utf8string& instr)
	{
		this->clear();
		return this->append(instr);
	};
	inline utf8string& assign(utf8string&& instr)
	{
		this->clear();
		return this->append(instr);
	};
	//-1 means all
	inline utf8string& assign(const utf8string& instr, size_type pos, size_type len = -1)
	{
		this->clear();
		return this->append(instr, pos, len);
	};
	//-1 means all
	inline utf8string& assign(utf8string&& instr, size_type pos, size_type len = -1)
	{
		this->clear();
		return this->append(instr, pos, len);
	};
	inline utf8string& assign(const char* instr)
	{
		this->clear();
		return this->append(instr);
	};
	//len is the length of chars in instr, not the length of utf8characters in instr and -1 means all
	inline utf8string& assign(const char* instr, size_type pos, size_type len = -1)
	{
		this->clear();
		return this->append(instr, pos, len);
	};
	//value must be a valid utf8character
	inline utf8string& assign(size_type count, const char* value)
	{
		this->clear();
		return this->append(count, value);
	};
	template<typename InputIterator>
	inline utf8string& assign(InputIterator first, InputIterator last)
	{
		this->clear();
		return this->append(first, last);
	};
	utf8string& insert(size_type index, const utf8string& instr)
	{
		__liter iter_tmp = get_iterator(index).__Get_m_iter();
		for (auto iter = instr.cbegin(); iter != instr.cend(); iter++)
		{
			m_str.insert(iter_tmp, iter.__Get_utf8char());
		}
		return *this;
	};
	inline utf8string& insert(size_type index, utf8string&& instr)
	{
		return insert(index, std::move(instr));
	};
	utf8string& insert(size_type index, const char* instr)
	{
		__liter iter_tmp = get_iterator(index).__Get_m_iter();
		while (*instr != '\0')
		{
			if (((*instr) & (1 << 7)) == 0)
			{
				utf8char c8;
				c8.c[0] = *instr;
				c8.c[1] = '\0';
				m_str.insert(iter_tmp, c8);
				instr++;
			}
			else
			{
				int u8clen = 0;
				for (int i = 7; i >= 0; i--)
				{
					if (((*instr) & (1 << i)) == 0)
					{
						break;
					}
					u8clen++;
				}
				utf8char c8;
				for (int i = 0; i < u8clen; i++)
				{
					c8.c[i] = *instr;
					instr++;
				}
				c8.c[u8clen] = '\0';
				m_str.insert(iter_tmp, c8);
			}
		}
		return *this;
	};
	utf8string& insert(const iterator _where, const utf8string& instr)
	{
		__liter iter_tmp = _where.__Get_m_iter();
		for (auto iter = instr.cbegin(); iter != instr.cend(); iter++)
		{
			m_str.insert(iter_tmp, iter.__Get_utf8char());
		}
		return *this;
	};
	inline utf8string& insert(const iterator _where, utf8string&& instr)
	{
		return insert(_where, std::move(instr));
	};
	utf8string& insert(const iterator _where, const char* instr)
	{
		__liter iter_tmp = _where.__Get_m_iter();
		while (*instr != '\0')
		{
			if (((*instr) & (1 << 7)) == 0)
			{
				utf8char c8;
				c8.c[0] = *instr;
				c8.c[1] = '\0';
				m_str.insert(iter_tmp, c8);
				instr++;
			}
			else
			{
				int u8clen = 0;
				for (int i = 7; i >= 0; i--)
				{
					if (((*instr) & (1 << i)) == 0)
					{
						break;
					}
					u8clen++;
				}
				utf8char c8;
				for (int i = 0; i < u8clen; i++)
				{
					c8.c[i] = *instr;
					instr++;
				}
				c8.c[u8clen] = '\0';
				m_str.insert(iter_tmp, c8);
			}
		}
		return *this;
	};
	//value should be one utf8character only
	utf8string& insert(const iterator _where, size_type count, const char* value)
	{
		__liter iter_tmp = _where.__Get_m_iter();
		utf8char c8(value);
		for (size_type i = 0; i < count; i++)
		{
			m_str.insert(iter_tmp, c8);
		}
		return *this;
	};
	template<typename InputIterator>
	utf8string& insert(iterator _where, InputIterator first, InputIterator last)
	{
		__liter iter_tmp = _where.__Get_m_iter();
		while (first != last)
		{
			m_str.insert(iter_tmp, first.__Get_utf8char());
			first++;
		}
		return *this;
	};
	inline utf8string& erase(size_type index)
	{
		return erase(get_iterator(index));
	};
	inline utf8string& erase(size_type index = 0, size_type len = -1)
	{
		if (len == -1)
		{
			return *this;
		}
		return erase(get_iterator(index), get_iterator(index + len));
	};
	template<typename InputIterator>
	utf8string& erase(InputIterator _where)
	{
		m_str.erase(_where.__Get_m_iter());
	};
	template<typename InputIterator>
	inline utf8string& erase(InputIterator _first, InputIterator _last)
	{
		m_str.erase(_first.__Get_m_iter(), _last.__Get_m_iter());
	};
	inline reference operator[](size_type index)
	{
		return *(begin() + index);
	};
	inline reference operator[](size_type index)const
	{
		return *(cbegin() + index);
	};
	reference at(size_type index)
	{
		if (index >= size())
		{
			throw std::out_of_range("utf8string::at()");
		}
		return *(begin() + index);
	};
	reference at(size_type index)const
	{
		if (index >= size())
		{
			throw std::out_of_range("utf8string::at()");
		}
		return *(cbegin() + index);
	};
	inline iterator get_iterator(size_type index)
	{
		return begin() + index;
	};
	inline const_iterator get_iterator(size_type index)const
	{
		return cbegin() + index;
	};
	//uft8c should be one utf8character only, or you should use append()
	inline void push_back(const char* utf8c)
	{
		m_str.push_back(utf8char(utf8c));
		return;
	}
	inline void pop_back() noexcept
	{
		m_str.pop_back();
		return;
	};
	utf8string substr(size_type pos, size_type len = -1)const noexcept
	{
		if (len == -1)
		{
			return utf8string(this->cbegin() + pos, this->cend());
		}
		return utf8string(this->cbegin() + pos, this->cbegin() + pos + len);
	};
	template<typename InputIterator>
	utf8string substr(InputIterator first, InputIterator last)const noexcept
	{
		return utf8string(first, last);
	};

	inline utf8string& operator=(const char* rhs)
	{
		this->clear();
		return this->append(rhs);
		return *this;
	};
	inline utf8string& operator+=(const utf8string& rhs)
	{
		return this->append(rhs);
	};
	inline utf8string& operator+=(const char* rhs)
	{
		return this->append(rhs);
	};
	inline utf8string& operator+(const utf8string& rhs)
	{
		return this->append(rhs);
	};
	inline utf8string& operator+(const char* rhs)
	{
		return this->append(rhs);
	};
	inline bool is_valid_utf8character(int index)
	{
		return is_valid_utf8character(this->get_iterator(index));
	};
	//remember catch the exception!!!
	bool is_valid_utf8character(iterator iter)
	{
		if (((*iter)[0] & (1 << 7)) == 0)
		{
			if ((*iter)[1] == '\0')
			{
				return true;
			}
			throw std::invalid_argument("utfustring contains a utf8character without correct end(\\0)");
			return false;
		}
		int cnt = 0;
		for (int i = 7; i >= 0; i--)
		{
			if (((*iter)[0] & (1 << i)) == 0)
			{
				if (cnt == 1)
				{
					throw std::invalid_argument("utfustring contains a invalid utf8character, its length is not correct");
					return false;
				}
				for (int i = 1; i < cnt; i++)// check the rest of the bytes 10xxxxxx
				{
					if (!((*iter)[i] & (1 << 7)) || ((*iter)[i] & (1 << 6)))
					{
						throw std::invalid_argument("utfustring contains a invalid utf8character, its rest parts are not correct(10xxxxxx)");
						return false;
					}
				}
				if ((*iter)[cnt] != '\0')
				{
					throw std::invalid_argument("utfustring contains a utf8character without correct end(\\0)");
					return false;
				}
				return true;
			}
			cnt++;
		}
		return false;
	};
	//return the iterator of the first invalid utf8 character
	//<br>if all are valid, return end()</br>
	iterator is_valid_utf8string()
	{
		for (auto i = this->begin(); i != this->end(); i++)
		{
			if (!is_valid_utf8character(i))
			{
				return i;
			}
		}
		return this->end();
	};
};

std::string charTobinary(char c)
{
	std::string s = "";
	for (int i = 7; i >= 0; i--)
	{
		if ((c & (1 << i)) != 0)
		{
			s += '1';
		}
		else
		{
			s += '0';
		}
	}
	return s;
}
std::string char32Tobinary(char32_t c)
{
	std::string s = "";
	for (int i = 31; i >= 0; i--)
	{
		if ((c & (1 << i)) != 0)
		{
			s += '1';
		}
		else
		{
			s += '0';
		}
	}
	return s;
}
#ifndef PYSTUFF_H_
#define PYSTUFF_H_

#include <string>
#include <sstream>
#include <vector>

namespace PyStuff
{
	template <typename T>
	class vector
	{
	private:
		std::vector<T> vector_;

	public:
		vector() = default;
		explicit vector(std::vector<T> vectorIn)
		{
			vector_.reserve(vectorIn.size());
			for (const auto& item : vectorIn)
			{
				vector_.push_back(item);
			}
		}

		vector& operator= (const vector& vectorIn)
		{
			vector_ = vectorIn.vector_;
		}

		vector& operator= (vector&& vectorIn) noexcept
		{
			vector_ = vectorIn.vector_;
		}

//		vector& operator= (braced-init-list<T> initializerList)

		/*
		 * Iterators
		 * -------------------------------------------------------------------------------------------------------------
		 */

		typename std::vector<T>::iterator begin() noexcept
		{
			return vector_.begin();
		}

		typename std::vector<T>::const_iterator begin() const noexcept
		{
			return vector_.begin();
		}

		typename std::vector<T>::iterator end() noexcept
		{
			return vector_.end();
		}

		typename std::vector<T>::const_iterator end() const noexcept
		{
			return vector_.end();
		}

		typename std::vector<T>::reverse_iterator rbegin() noexcept
		{
			return vector_.rbegin();
		}

		typename std::vector<T>::const_reverse_iterator rbegin() const noexcept
		{
			return vector_.rbegin();
		}

		typename std::vector<T>::reverse_iterator rend() noexcept
		{
			return vector_.rend();
		}

		typename std::vector<T>::const_reverse_iterator rend() const noexcept
		{
			return vector_.rend();
		}

		typename std::vector<T>::const_iterator cbegin() const noexcept
		{
			return vector_.cbegin();
		}

		typename std::vector<T>::const_iterator cend() const noexcept
		{
			return vector_.cend();
		}

		typename std::vector<T>::const_reverse_iterator crbegin() const noexcept
		{
			return vector_.crbegin();
		}

		typename std::vector<T>::const_reverse_iterator crend() const noexcept
		{
			return vector_.crend();
		}

		/*
		 * Capacity
		 * -------------------------------------------------------------------------------------------------------------
		 */

		size_t size() const noexcept
		{
			return vector_.size();
		}

		size_t max_size() const noexcept
		{
			return vector_.max_size();
		}

		void resize (size_t n)
		{
			vector_.resize(n);
		}

		void resize(size_t n, const T& value)
		{
			vector_.resize(n, value);
		}

		size_t capacity() const noexcept
		{
			return vector_.capacity();
		}

		bool empty() const noexcept
		{
			return vector_.empty();
		}

		void reserve (size_t n)
		{
			vector_.reserve(n);
		}

		void shrink_to_fit()
		{
			vector_.shrink_to_fit();
		}

		/*
		 * Element Access
		 * -------------------------------------------------------------------------------------------------------------
		 */

		T& operator[] (size_t index)
		{
			return vector_[index];
		}

		const T& operator[] (size_t index) const
		{
			return vector_[index];
		}

		T& at(size_t index)
		{
			return vector_.at(index);
		}

		const T& at(size_t index) const
		{
			return vector_.at(index);
		}

		T& front()
		{
			return vector_.front();
		}

		const T& front() const
		{
			return vector_.front();
		}

		T& back()
		{
			return vector_.back();
		}

		const T& back() const
		{
			return vector_.back();
		}

		T* data() noexcept
		{
			return vector_.data();
		}

		const T* data() const noexcept
		{
			return vector_.data();
		}

		/*
		 * Modifiers
		 * -------------------------------------------------------------------------------------------------------------
		 */

		// TODO iterator assign

		void assign(size_t n, const T& value)
		{
			vector_.assign(n, value);
		}

		// TODO initializer list assign

		void push_back(const T& value)
		{
			vector_.push_back(value);
		}

		void push_back(T&& value)
		{
			vector_.push_back(value);
		}

		void pop_back()
		{
			vector_.pop_back();
		}

		typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator position, const T& value)
		{
			return vector_.insert(position, value);
		}

		typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator position, size_t n, const T& value)
		{
			return vector_.insert(position, n, value);
		}

		// TODO range insert

		typename std::vector<T>::iterator insert(typename std::vector<T>::const_iterator position, T&& value)
		{
			return vector_.insert(position, value);
		}

		// TODO initializer list insert

		typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator position)
		{
			return vector_.erase(position);
		}

		typename std::vector<T>::iterator erase(typename std::vector<T>::const_iterator first, typename std::vector<T>::const_iterator last)
		{
			return vector_.erase(first, last);
		}

		void swap (vector<T>& vectorIn)
		{
			vector_.swap(vectorIn.vector_);
		}

		void clear() noexcept
		{
			vector_.clear();
		}

		// TODO emplace

		// TODO emplace_back

		/*
		 * My custom functions
		 * -------------------------------------------------------------------------------------------------------------
		 */

		typename std::vector<T>::iterator find(const T& value)
		{
			auto it = vector_.begin();
			while (it != vector_.end())
			{
				if (*it == value)
				{
					break;
				}
				it++;
			}
			return it;
		}

		bool contains(const T& value)
		{
			return find(value) != vector_.end();
//			for (const auto& item : vector_)
//			{
//				if (item == value)
//				{
//					return true;
//				}
//			}
//			return false;
		}

		std::string join(const std::string& joiner = ", ")
		{
			std::stringstream ss;
			std::string sep;
			for (const auto& item : vector_)
			{
				ss << sep << item;
				sep = joiner;
			}
			return ss.str();
		}

		void extend(const vector<T>& vectorIn)
		{
			vector_.reserve(vector_.size() + vectorIn.size());
			for (const auto& item : vectorIn)
			{
				vector_.push_back(item);
			}
		}

		void removeValue(const T& value)
		{
			if (contains(value))
			{
				vector_.erase(find(value));
			}
		}

		void removeAllValue(const T& value)
		{
			while (contains(value))
			{
				vector_.erase(find(value));
			}
		}

		size_t indexOf(const T& value)
		{
			for (size_t i = 0; i < vector_.size(); i++)
			{
				if (vector_.at(i) == value)
				{
					return i;
				}
			}
			return -1;
		}

		size_t lastIndexOf(const T& value)
		{
			for (size_t i = vector_.size() - 1; i >= 0; i--)
			{
				if (vector_.at(i) == value)
				{
					return i;
				}
			}
			return -1;
		}

		size_t count(const T& value)
		{
			size_t sum = 0;
			for (const auto& item : vector_)
			{
				if (item == value)
				{
					sum++;
				}
			}
			return sum;
		}

		T max()
		{
			if (vector_.empty())
			{
				return T();
			}
			T maximum = vector_.front();
			for (size_t i = 1; i < vector_.size(); i++)
			{
				maximum = std::max(maximum, vector_.at(i));
			}
			return maximum;
		}

		T min()
		{
			if (vector_.empty())
			{
				return T();
			}
			T minimum = vector_.front();
			for (size_t i = 1; i < vector_.size(); i++)
			{
				minimum = std::min(minimum, vector_.at(i));
			}
			return minimum;
		}

		vector<T> slice(size_t start, size_t end)
		{
			vector<T> newVector;
			newVector.reserve(end - start);
			for (size_t i = start; i < end; i++)
			{
				newVector.push_back(vector_.at(i));
			}
			return newVector;
		}

		T sum()
		{
			if (vector_.empty())
			{
				return T();
			}
			T sum = vector_.front();
			for (size_t i = 1; i < vector_.size(); i++)
			{
				sum += vector_.at(i);
			}
			return sum;
		}

	};
}

#endif //PYSTUFF_H_

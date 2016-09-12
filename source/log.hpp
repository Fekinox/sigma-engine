#ifndef __LOG_H__
	#define __LOG_H__

	#include <iostream>
	#include <sstream>
	#include <fstream>
	#include <type_traits>

	#define DEBUG 1

	#define TOFILE 1

	#if DEBUG == 1
		#define LOG(...) log(Part<bool, bool>() << __VA_ARGS__)

		template<typename T> struct PartTrait { typedef T Type; };

		#ifndef NOINLINE_ATTRIBUTE
			#ifdef __ICC
				#define NOINLINE_ATTRIBUTE __attribute__(( noinline ))
			#else
				#define NOINLINE_ATTRIBUTE
			#endif //__ICC
		#endif //NOINLINE_ATTRIBUTE

		//Marked as noinline to minimize amount of log instructions

		template<typename T>
		void log(const T& msg) NOINLINE_ATTRIBUTE
		{
			#if TOFILE == 1
				std::ofstream logfile("log.txt", std::ios_base::out | std::ios_base::app);
				#define DEST logfile
			#else
				#define DEST std::cout
			#endif
			DEST << msg << std::endl;
		}

		template<typename TValue, typename TPreviousPart>
		struct Part : public PartTrait<Part<TValue, TPreviousPart> >
		{
			Part()
				: value(nullptr), prev(nullptr)
			{ }

			Part(const Part<TValue, TPreviousPart>&) = default;
			Part<TValue, TPreviousPart> operator=(
								   const Part<TValue, TPreviousPart>&) = delete;

			Part(const TValue& v, const TPreviousPart& p)
				: value(&v), prev(&p)
			{ }

			std::ostream& output(std::ostream& os) const
			{
				if (prev)
					os << *prev;
				if (value)
					os << *value;
				return os;
			}

			const TValue* value;
			const TPreviousPart* prev;
		};

		// Specialization for stream manipulators (eg endl)

		typedef std::ostream& (*PfnManipulator)(std::ostream&);

		template<typename TPreviousPart>
		struct Part<PfnManipulator, TPreviousPart>
			: public PartTrait<Part<PfnManipulator, TPreviousPart> >
		{
			Part()
				: pfn(nullptr), prev(nullptr)
			{ }

			Part(const Part<PfnManipulator, TPreviousPart>& that) = default;
			Part<PfnManipulator, TPreviousPart> operator=(const Part<PfnManipulator,
														  TPreviousPart>&) = delete;

			Part(PfnManipulator pfn_, const TPreviousPart& p)
			: pfn(pfn_), prev(&p)
			{ }

			std::ostream& output(std::ostream& os) const
			{
				if (prev)
					os << *prev;
				if (pfn)
					pfn(os);
				return os;
			}

			PfnManipulator pfn;
			const TPreviousPart* prev;
		};

		template<typename TPreviousPart, typename T>
		typename std::enable_if<
			std::is_base_of<PartTrait<TPreviousPart>, TPreviousPart>::value,
			Part<T, TPreviousPart> >::type
		operator<<(const TPreviousPart& prev, const T& value)
		{
			return Part<T, TPreviousPart>(value, prev);
		}

		template<typename TPreviousPart>
		typename std::enable_if<
			std::is_base_of<PartTrait<TPreviousPart>, TPreviousPart>::value,
			Part<PfnManipulator, TPreviousPart> >::type
		operator<<(const TPreviousPart& prev, PfnManipulator value)
		{
			return Part<PfnManipulator, TPreviousPart>(value, prev);
		}

		template<typename TPart>
		typename std::enable_if<
			std::is_base_of<PartTrait<TPart>, TPart>::value,
			std::ostream&>::type
		operator<<(std::ostream& os, const TPart& part)
		{
			return part.output(os);
		}
	#else
		#define LOG(...) ;
	#endif
#endif //LOG_H

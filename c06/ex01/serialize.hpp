#ifndef __SERIALIZE_H__
# define __SERIALIZE_H__

# include <cstdint>
# include <string>


typedef struct	s_date
{
	std::string	strWhatever;
	int			intWhatever;
	float		floatWhatever;
}	Data;

uintptr_t serialize(Data *ptr);
Data* deserialize(uintptr_t raw);

#endif

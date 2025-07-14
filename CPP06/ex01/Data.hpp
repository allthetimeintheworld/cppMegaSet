#ifndef DATA_HPP
# define DATA_HPP

# include <string>

struct		Data
{
	int		id;
	std::string name;
	double	value;
	bool	active;

	Data();
	Data(int id, const std::string &name, double value, bool active);
	Data(const Data &other);
	Data &operator=(const Data &other);
	~Data();

	void display() const;
};

#endif

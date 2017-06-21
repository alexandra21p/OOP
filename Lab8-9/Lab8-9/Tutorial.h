#pragma once
#include <iostream>
#include <string>


class Duration
{
public:
	double minutes;
	double seconds;
public:
	Duration() : minutes(0), seconds(0) {}
	Duration(double min, double sec) : minutes(min), seconds(sec) {}

	double getMinutes() { return minutes; }
	double getSeconds() { return seconds; }
	void setMinutes(double min) { minutes = min; }
	void getSeconds(double sec) { seconds = sec; }
	friend std::ostream &operator<<(std::ostream &output,
		Duration &D)
	{
		output << D.minutes << ':' << D.seconds << '\n';
		return output;
	}


};


class Tutorial
{

private:
	std::string title;
	std::string presenter;
	Duration duration;
	double likes;
	std::string link; // link towards the online resource containing the tutorial

public:
	// default constructor for a tutorial
	Tutorial();

	// constructor with parameters
	//Tutorial(const std::string& title, const std::string& presenter, const Duration& duration, const double& likes, const std::string& link);

	Tutorial(std::string t, std::string p, Duration d, double li, std::string lk);

	~Tutorial();

	// getters for the class fields
	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter; }
	Duration getDuration() const { return duration; }
	double getNrLikes() const { return likes; }
	std::string getLink() const { return link; }

	// setters for the class fields
	void setTitle(std::string t) { title = t; }
	void setPresenter(std::string p) { presenter = p; }
	void setDuration(Duration d) { duration = d; }
	void setNrLikes(double l) { likes = l; }
	void setLink(std::string lk) { link = lk; }

	// Plays the current tutorial: the page corresponding to the source link is opened in the chrome browser.
	void play();

	friend std::ostream &operator<<(std::ostream &output,
		Tutorial &T)
	{
		output << T.title << ',' << T.presenter << ',' << T.duration.getMinutes() << ":" << T.duration.getSeconds() << ',' << T.likes <<  ',' << T.link << '\n';
		return output;
	}

	inline bool operator==(const Tutorial& rhs) { return (rhs.title == this->title && rhs.presenter == this->presenter); }

	friend std::istream &operator>>(std::istream  &input, Tutorial &T)
	{
		std::string st;
		getline(input, st, ',');
		T.title = st;
		getline(input, st, ',');
		T.presenter = st;
		getline(input, st, ':');
		T.duration.minutes = atoi(st.c_str());
		getline(input, st, ',');
		T.duration.seconds = atoi(st.c_str());
		getline(input, st, ',');
		T.likes = atoi(st.c_str());
		input >> st;
		T.link = st;
		return input;
	}
};


/**
* Generic exception used in the application
* We will derive specialised exceptions from this class
*/
class AppException {
public:
	AppException(const std::string& msg) {
		this->msg = msg;
	}
	const std::string& getMsg() const {
		return msg;
	}

private:
	std::string msg;
};

CREATE TABLE User(
username VARCHAR(20) PRIMARY KEY,
password VARCHAR(15),
displayname VARCHAR(15),
);
CREATE TABLE Tweet(
TTime time (20),
TweetID INT,
draft VARCHAR(140),
content VARCHAR(140),
Totallikes INT,
Totalcomments INT,
PRIMARY KEY (TTime, TweetID)
);
CREATE TABLE Retweet(
username VARCHAR(20) REFERENCES User(username),
TTTime time (20) REFERENCES Tweet(TTime),
TweetID INT REFERENCES Tweet(TweetID),
content VARCHAR(140),
PRIMARY KEY (username, TTime, TweetID),
FOREIGN KEY (username, TTime, TweetID),
);
CREATE TABLE Creates(
username VARCHAR(20) REFERENCES User(username),
TTime time (20) REFERENCES Tweet(TTime),
TweetID INT REFERENCES Tweet(TweetID),
PRIMARY KEY (username, TTime, TweetID),
FOREIGN KEY (username, TTime, TweetID),
);
CREATE TABLE Likes(
username VARCHAR(20) REFERENCES User(username),
TTime time (20) REFERENCES Tweet(TTime),
TweetID INT REFERENCES Tweet(TweetID),
PRIMARY KEY (username, TTime, TweetID),
FOREIGN KEY (username, TTime, TweetID),
);
CREATE TABLE Comment(
username VARCHAR(20) REFERENCES User(username),
TTime time (20) REFERENCES Tweet(TTime),
TweetID INT REFERENCES Tweet(TweetID),
comment varchar(255),
PRIMARY KEY (username, TTime, TweetID),
FOREIGN KEY (username, TTime, TweetID),
);
CREATE TABLE Follows(
username VARCHAR(20) PRIMARY KEY REFERENCES User(username),
);

CREATE DATABASE Project;

USE Project;

CREATE TABLE users(
	user_id int(11) PRIMARY KEY not null AUTO_INCREMENT,
	username varchar(1000) not null,
	admin_status boolean not null
);

INSERT INTO users (username, admin_status) VALUES ("admin", true);

CREATE TABLE passwords(
	pass_id int(11) PRIMARY KEY not null AUTO_INCREMENT,
	user_id int(11) not null,
	password varchar(1000) not null,
	FOREIGN KEY (user_id) REFERENCES users(user_id)
);

INSERT INTO passwords (user_id, password) VALUES ((SELECT user_id FROM users WHERE username="admin"), "admin");

CREATE TABLE hashes(
	hash_uuid int(11) PRIMARY KEY not null AUTO_INCREMENT,
	compute_time int(11) not null,
	address varchar(1000) not null,
	received_time timestamp not null,
	result varchar(1000) not null
);

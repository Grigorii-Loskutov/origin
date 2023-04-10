CREATE TABLE IF NOT EXISTS Artist (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) NOT NULL,
	psevdo_name VARCHAR(40)
);

CREATE TABLE IF NOT EXISTS Jenre (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) NOT NULL
);

CREATE TABLE IF NOT EXISTS Album (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) NOT NULL,
	production_year DATE not null
);

CREATE TABLE IF NOT EXISTS Track (
	id SERIAL PRIMARY KEY,
	album_id INTEGER NOT NULL REFERENCES Album(id),
	name VARCHAR(40) NOT NULL,
	duration INTEGER not null
);

CREATE TABLE IF NOT EXISTS Collection (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) NOT NULL,
	production_year DATE not null
);


CREATE TABLE IF NOT EXISTS ArtistAlbum (
	artist_id INTEGER REFERENCES Artist(id),
	album_id INTEGER REFERENCES Album(id),
	CONSTRAINT pk PRIMARY KEY (artist_id, album_id)
);

CREATE TABLE IF NOT EXISTS ArtistJenre (
	artist_id INTEGER REFERENCES Artist(id),
	jenre_id INTEGER REFERENCES Jenre(id),
	CONSTRAINT pk PRIMARY KEY (artist_id, jenre_id)
);


CREATE TABLE IF NOT EXISTS TrackCollection (
	track_id INTEGER REFERENCES Track(id),
	collection_id INTEGER REFERENCES Collection(id),
	CONSTRAINT pk PRIMARY KEY (track_id, collection_id)
);
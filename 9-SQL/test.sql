-- Alguns testes com sql :v
CREATE TABLE classroom(
	ID INT NOT NULL,
	Amount_Students INT,
	Representative VARCHAR(125),
	PRIMARY KEY(ID)
);
CREATE TABLE pupil(
	Last_name VARCHAR(100) NOT NULL,
	First_name VARCHAR(25),
	Class INT,
	Notes FLOAT,
	Influence INT NOT NULL,
	PRIMARY KEY(Last_name),
	UNIQUE(Last_name),
	CONSTRAINT FK_Pupil FOREIGN KEY (Class) REFERENCES classroom(ID)
);
--
CREATE OR REPLACE FUNCTION update_amount_pupils()RETURNS TRIGGER AS $$
DECLARE row RECORD;
BEGIN
	FOR row IN SELECT ID FROM classroom LOOP
		UPDATE classroom SET Amount_Students=(SELECT COUNT(Class)FROM pupil WHERE Class=row.ID) WHERE ID=row.ID;
	END LOOP;
	RETURN row;
END;
$$ LANGUAGE plpgsql;
--
CREATE TRIGGER update_pupil AFTER UPDATE OR INSERT OR DELETE ON pupil
EXECUTE FUNCTION update_amount_pupils();

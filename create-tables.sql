DROP TABLE cinema.Cinema CASCADE;
DROP TABLE cinema.Funcionario CASCADE;
DROP TABLE cinema.Filme CASCADE;
DROP TABLE cinema.Sala CASCADE;
DROP TABLE cinema.Sessao CASCADE;
DROP TABLE cinema.Ingresso CASCADE;


CREATE TABLE IF NOT EXISTS cinema.Cinema 
(Id uuid PRIMARY KEY, Nome varchar, Endereco varchar, Abertura time, Fechamento time);

CREATE TABLE IF NOT EXISTS cinema.Funcionario 
(Id uuid PRIMARY KEY, Cinema_Id uuid, Nome varchar, CPF varchar, Salario numeric, FOREIGN KEY (Cinema_Id) REFERENCES Cinema (Id));

CREATE TABLE IF NOT EXISTS cinema.Filme
(Id uuid PRIMARY KEY, Titulo varchar, Duracao numeric, Genero varchar, Descricao varchar, Indicacao numeric);

CREATE TABLE IF NOT EXISTS cinema.Sala 
(Id uuid PRIMARY KEY, Cinema_Id uuid, Total_assentos numeric, Assentos_disponiveis numeric, Tipo_tela varchar, FOREIGN KEY (Cinema_id) REFERENCES cinema.Cinema (Id));

CREATE TABLE IF NOT EXISTS cinema.Sessao
(Id uuid PRIMARY KEY, Filme_Id uuid, Sala_Id uuid, Horario timestamptz, FOREIGN KEY (Filme_Id) REFERENCES cinema.Filme (Id), FOREIGN KEY (Sala_Id) REFERENCES cinema.Sala (Id));

CREATE TABLE IF NOT EXISTS cinema.Ingresso 
(Id uuid PRIMARY KEY, Sessao_id uuid, Valor numeric(1000, 3), Tipo varchar, FOREIGN KEY (Sessao_id) REFERENCES cinema.Sessao (Id));

show databases;
use mysql;
show tables;
desc User;
select * from User;

create user madang@localhost identified by 'madang';
create user mdguest@'localhost' identified by 'mdguest';
create user mdguest2 identified by 'mdguest2';
select *from User where User like 'mdguest2';

grant all privileges on *.* to madang@localhost with grant option;
flush privileges;
show grants for madang@localhost;

grant select on madang.book to mdguest@localhost;
use madang;
select * from book;

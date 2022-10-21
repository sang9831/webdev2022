use madang;
CREATE TABLE Book (
    `bookid` INT PRIMARY KEY,
    `bookname` VARCHAR(40) DEFAULT NULL,
    `publisher` VARCHAR(40) DEFAULT NULL,
    `price` INT DEFAULT NULL
);
CREATE TABLE Customer (
    `custid` INTEGER PRIMARY KEY,
    `name` VARCHAR(40),
    `address` VARCHAR(50),
    `phone` VARCHAR(20)
);
CREATE TABLE Orders (
    `orderid` INT PRIMARY KEY,
    `custid` INT,
    `bookid` INT,
    `saleprice` INT,
    `orderdate` DATE,
    FOREIGN KEY (custid)
        REFERENCES Customer (custid),
    FOREIGN KEY (bookid)
        REFERENCES Book (bookid)
);
insert into Book value(1, '축구의 역사', '굿스포츠', 7000);
insert into Book value(2, '축구아는 여자', '나무수', 13000);
insert into Book value(3, '축구의 이해', '대한미디어', 22000);
insert into Book value(4, '골프 바이블', '대한미디어', 35000);
insert into Book value(5, '피겨 교본', '굿스포츠', 8000);
insert into Book value(6, '역도 단계별기술', '굿스포츠', 6000);
insert into Book value(7, '야구의 추억', '이상미디어', 20000);
insert into Book value(8, '야구를 부탁해', '이상미디어', 13000);
insert into Book value(9, '올림픽 이야기', '삼성당', 7500);
insert into Book value(10, 'Olympic Champions', 'Pearson', 13000);

insert into Customer values(1, '박지성', '영국 맨체스타', '000-5000-0001');
insert into Customer values(2, '김연아', '대한민국 서울', '000-6000-0001');
insert into Customer values(3, '장미란', '대한민국 강원도', '000-7000-0001');
insert into Customer values(4, '추신수', '미국 클리블랜드', '000-8000-0001');
insert into Customer values(5, '박세리', '대한민국 대전', NULL);

insert into Orders values(1, 1, 1, 6000, STR_TO_DATE('2014-07-01', '%Y-%m-%d'));
insert into Orders values(2, 1, 3, 21000, STR_TO_DATE('2014-07-03', '%Y-%m-%d'));
insert into Orders values(3, 2, 5, 8000, STR_TO_DATE('2014-07-03', '%Y-%m-%d'));
insert into Orders values(4, 3, 6, 6000, STR_TO_DATE('2014-07-04', '%Y-%m-%d'));
insert into Orders values(5, 4, 7, 20000, STR_TO_DATE('2014-07-05', '%Y-%m-%d'));
insert into Orders values(6, 1, 2, 12000, STR_TO_DATE('2014-07-07', '%Y-%m-%d'));
insert into Orders values(7, 4, 8, 13000, STR_TO_DATE('2014-07-07', '%Y-%m-%d'));
insert into Orders values(8, 3, 10, 12000, STR_TO_DATE('2014-07-08', '%Y-%m-%d'));
insert into Orders values(9, 2, 10, 7000, STR_TO_DATE('2014-07-09', '%Y-%m-%d'));
insert into Orders values(10, 3, 8, 13000, STR_TO_DATE('2014-07-10', '%Y-%m-%d'));

 
-- group by  
select custid, COUNT(*) AS 도서수량, SUM(saleprice) AS 총액 from orders group by custid;
select custid, COUNT(*) AS 도서수량 from orders where saleprice >= 8000 group by custid having count(*) >= 2;

select * from customer, orders;
select * from customer, orders where customer.custid = orders.custid order by customer.custid;

select customer.name, orders.saleprice from customer, orders where customer.custid = orders.custid;

select customer.name, sum(orders.saleprice) from customer, orders where customer.custid = orders.custid group by customer.name order by customer.name;

select customer.name, book.bookname from customer, orders, book where customer.custid = orders.custid and orders.bookid = book.bookid and book.price = 20000;

-- 외부조인 where안쓰고 on씀
select customer.name, orders.saleprice from customer left outer join orders on customer.custid = orders.custid;

 select book.bookname, book.price from book where price = (select max(price) from book);
 
 select customer.name from customer where custid in (select custid from orders);
 
 select customer.name from customer where custid in (select custid from orders where bookid in (select bookid from book where book.publisher = '대한미디어'));
 
 select * from book b1 where b1.price > (select avg(b2.price) from book b2 where b2.publisher = b1.publisher);
 select customer.name from customer where address like '대한민국%' union select customer.name from customer where custid in (select custid from orders);
 select cs.name, cs.address from customer cs where exists (select * from orders od where cs.custid = od.custid);
-- 스칼라 부속질의
-- 마당서점의 고객별 판매액을 보이시오(고객이름과 고객별 판매액 출력)
SELECT 
    (SELECT 
            name
        FROM
            customer cs
        WHERE
            cs.custid = od.custid) 'name',
    SUM(saleprice) 'total'
FROM
    orders od
GROUP BY od.custid;

-- orders테이블에 새로운속성 도서이름 추가
alter table orders add bname varchar(40);

update orders set bname='피겨 교본' where bookid=1;

update orders set bname=(select bookname from book where book.bookid=orders.bookid);
select * from orders;

-- 인라인 뷰
-- 고객번호가 2 이하인 고객의 판매액을 보이시오(고객이름과 고객별 판매액 출력)
select cs.name, sum(od.saleprice) 'total' from (select custid, name from customer where custid<=2) cs, orders od where cs.custid=od.custid group by cs.name;

-- 중첩질의
-- 평균 주문금액 이하의 주문에 대해서 주문번호와 금액을 보이시오
select orderid, saleprice from orders where saleprice <=(select avg(saleprice) from orders);
-- 각 고객의 평균 주문금액보다 큰 금액의 주문 내역에 대해서 주문번호, 고객번호, 금액을 보이시오
select orderid, custid, saleprice from orders md where saleprice > (select avg(saleprice) from orders so where md.custid=so.custid);
-- 코드를 작성해주세요
with chan as(
select EMP_NO,sum(score) as score from HR_GRADE
where year = 2022
group by EMP_NO
order by 2 desc
limit 1
    )

select b.score, a.EMP_NO,a.EMP_NAME ,a.POSITION,a.EMAIL from HR_EMPLOYEES as a
inner join chan as b on b.EMP_NO = a.EMP_NO


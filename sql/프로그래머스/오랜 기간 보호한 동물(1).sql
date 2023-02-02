
select name,datetime from animal_ins as a
where not exists (select b.animal_id
                  from animal_outs as b
                 where a.animal_id = b.animal_id
                )
order by datetime
limit 3;

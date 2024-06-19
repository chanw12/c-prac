select ID,(select IFNULL(count(PARENT_ID),0) from ECOLI_DATA where PARENT_ID = A.ID) as CHILD_COUNT
from ECOLI_DATA as A
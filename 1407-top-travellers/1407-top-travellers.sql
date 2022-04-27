select users.name,coalesce(c.travelled_distance,0) as travelled_distance from users left join 
    (select user_id,SUM(distance) as travelled_distance from Rides r group by user_id) as c
on users.id = c.user_id order by c.travelled_distance desc,name asc;
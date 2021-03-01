-- Put only sql structure in this file (create table if exists, delete table, alter table etc...).
-- If you don't use this database, then delete this file.
create table sponsorship
(
    first_account_id  int      not null,
    second_account_id int      not null,
    begin             datetime null,
    primary key (first_account_id, second_account_id)
);


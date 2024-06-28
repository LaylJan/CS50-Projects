-- Keep a log of any SQL queries you execute as you solve the mystery.
--Check start of crime scenne
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;
SELECT name, transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
--Check Peoplez
SELECT * FROM people;
--Check withdraw on july 28
SELECT atm_transactions.account_number, people.name, atm_transactions.amount
FROM atm_transactions
JOIN bank_accounts ON atm_transactions.account_number = bank_accounts.account_number
JOIN people ON bank_accounts.person_id = people.id
WHERE atm_transactions.month = 7 AND atm_transactions.day = 28 AND atm_transactions.year = 2021
AND atm_transactions.transaction_type = 'withdraw' AND atm_transactions.atm_location = 'Leggett Street'
ORDER BY name ASC;

--Bakery logs
SELECT license_plate
FROM bakery_security_logs
WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND minute BETWEEN 15 AND 25;


SELECT name, passport_number
FROM people
WHERE license_plate IN ('94KL13X', '6P58WS2', 'F328GD8', 'G412CB7', 'L93JTIZ', '322W7JE', '0NTHK55');

SELECT * FROM passengers JOIN flights ON passengers.flight_id = flights.id
WHERE year = 2021 AND month = 7 AND day = 29 AND passport_number in (3592750733, 5773159633)
ORDER BY passport_number ASC;

SELECT caller, receiver
FROM phone_calls
WHERE year = 2021 AND month = 7 AND day = 28 AND duration < 60;


SELECT DISTINCT people.name, phone_calls.caller, phone_calls.receiver
FROM people
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE phone_calls.year = 2021 AND phone_calls.month = 7 AND phone_calls.day = 28 ORDER BY name ASC;


SELECT DISTINCT
    people.name AS caller_name,
    phone_calls.caller,
    people_receiver.name AS receiver_name,
    phone_calls.receiver
FROM
    people
JOIN
    phone_calls ON people.phone_number = phone_calls.caller
LEFT JOIN
    people AS people_receiver ON phone_calls.receiver = people_receiver.phone_number
WHERE
    phone_calls.year = 2021
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND duration < 60
ORDER BY
    caller_name ASC;


94KL13X
6P58WS2
F328GD8
G412CB7
L93JTIZ
322W7JE
0NTHK55
1106N58

3592750733
5773159633


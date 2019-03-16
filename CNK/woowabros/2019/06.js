function solution(totalTicket, logs) {
  `use strict`
  let answer = [];
  let connect_id;
  let connect_end_time;

  let start_dt = new Date(2019, 03, 16, 9, 00, 00);
  let end_dt = new Date(2019, 03, 16, 9, 59, 00);

  for (var i = 0; i < logs.length; i++) {
    if (totalTicket == 0) {
      break;
    }

    let log = logs[i].split(' ');
    let id = log[0];
    let action = log[1];
    let time = log[2];
    let [hh, mm, ss] = time.split(':');
    let time_dt = new Date(2019, 03, 16, Number(hh), Number(mm), Number(ss));
    if (action == 'request') {
      if (start_dt.getTime() <= time_dt.getTime() && time_dt.getTime() <= end_dt.getTime()) { // 시간내에 접속했으면
        if (!connect_id) {  // 접속 가능
          connect_id = id;
          connect_end_time = new Date(2019, 03, 16, Number(hh), Number(mm), Number(ss));
          connect_end_time.setMinutes(connect_end_time.getMinutes() + 1);          
        } else {;
          if(connect_end_time.getTime() < time_dt.getTime()) {  // 접속 가능
            answer.push(connect_id);  // 기존 접속자는 구매 했음.
            totalTicket--;

            connect_id = id;
            connect_time = time_dt;
            connect_end_time = time_dt + 1000*60;
          }
        }
      }
    } else {  // 중간에 접속 종료한 경우
      connect_id = '';
    }
  }

  if (totalTicket > 0 && connect_id) {    
    answer.push(connect_id);
    totalTicket--;
  }

  return answer.sort();
}

console.log(
solution(2000, [
  "woni request 09:12:29",
  "brown request 09:23:11",
  "brown leave 09:23:44",
  "jason request 09:33:51",
  "jun request 09:33:56",
  "cu request 09:34:02"
]));
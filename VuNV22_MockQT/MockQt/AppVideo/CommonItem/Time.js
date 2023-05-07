function getCurrentDateTime() {
    const now = new Date();
    const year = now.getFullYear().toString();
    const month = (now.getMonth() + 1).toString().padStart(2, '0');
    const day = now.getDate().toString().padStart(2, '0');
                const days = ["Chủ Nhật", "Thứ Hai", "Thứ Ba", "Thứ Tư", "Thứ Năm", "Thứ Sáu", "Thứ Bảy"];
    var dayOfWeek = days[now.getDay()];
    dayOfWeek = dayOfWeek.toString();
    var hours = now.getHours().toString().padStart(2, '0');
    var AMorPM = "AM"
    if(hours >=12){
        hours = hours-12
        AMorPM = "PM"
    }

    const minutes = now.getMinutes().toString().padStart(2, '0');
    const seconds = now.getSeconds().toString().padStart(2, '0');

    return  `${hours}:${minutes} ${AMorPM} ${day}.${month}`
}

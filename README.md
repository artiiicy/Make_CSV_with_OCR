# Make_CSV_with_OCR
OCR결과로 나온 txt파일들을 csv에 입력하여 DB에 넣기 편하게 만들어주는 프로그램

# 1. txt file encoding
TxtEncodingProg.exe를 사용하여 txt file을 일괄적으로 인코딩 해준다.

OCR 결과로 나온 txt파일의 인코딩은 UTF-8인데 한글이 깨지는 것을 방지하기 위하여 이를 ANSI로 인코딩한다.

(해당 프로그램은 http://blog.daum.net/masoris20/26 에서 제작된 프로그램입니다)

# 2. make csv file
txt file들을 파일명, 파일의 내용(OCR 결과) pair로 csv파일을 만든다.

# 3. insert csv contents to DB
데이터베이스에 csv 내용을 key - value 값으로 하여 넣어준다.

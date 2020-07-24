import os
import shutil
import re
import xlsxwriter
from xlrd import open_workbook
import zipfile
import rarfile
# import Unrar

# step 1
# ------------------------
# HW_Structure

if not os.path.exists('Q6.txt'):  # text does exist?
    print("File 'Q6.txt' does not exists!")

text = open('Q6.txt',"r")

lines = text.readlines()
HWS = re.search('HW\d',lines[0]).group()

Questions = []
for i in range (1 , len(lines)):
    # searchFolder = re.match(r'Q\d', lines[i]) # =)
    # line = re.sub(r'\W'," ",lines[i])
    Questions.append(lines[i].replace(', ', ' ').replace(':', '').split())

# print(Questions)
# step 2
# ------------------------
# Categorized_HW2

dirname1 = 'Categorized_' + HWS

if os.path.exists(dirname1):
    shutil.rmtree(dirname1)
os.makedirs(dirname1)

QS = []
for q in Questions:
    os.makedirs(dirname1+'/'+q[0])
    QS.append(q[0])

# step 3
# -------------------------
# AP-HW2.zip

excelnames = []
zfiles = zipfile.ZipFile('AP-'+ HWS + '.zip','r')
zfiles.extractall('AP-'+ HWS)
project_path = os.getcwd()
os.chdir('AP-'+ HWS)
AP_HW2_path = os.getcwd()
cnt = 0
# writing excel
workbook = xlsxwriter.Workbook('Problems.xlsx')
worksheet = workbook.add_worksheet()
for Folder in os.listdir(os.getcwd()):
    studentname = re.match(r'[A-Za-z .(){}*&$#@]+', Folder).group()
    print('Processing->' , studentname)
    os.chdir(AP_HW2_path)
    os.chdir(Folder)
    folderproblem = True
    for zips in os.listdir(os.getcwd()):
        searchzip = re.search(r'AP-'+HWS+'-\d{7}.zip', zips)
        studentnum = re.search(r'\d{7}', zips)
        if searchzip:
            folderproblem = False
        # ZIPFILES
        if zipfile.is_zipfile(zips):
            zip = zipfile.ZipFile(zips)
            zip.extractall(studentname)
            os.chdir(studentname)
            for filepath in zip.namelist():
                for ques in Questions:
                    for i in range (1,len(ques)):
                        path = re.search(r'.*[Q|q]'+ques[0][1]+'.*'+ques[i]+'$', filepath)
                        if path:
                            filename = re.search(r'\w+'+'.'+ques[i]+'$',path.group()).group()
                            cpath = path.group().replace('/','\\')
                            if studentnum:
                                shutil.copyfile(os.getcwd() + '\\' + cpath,
                                                project_path + '\\' + dirname1 + '\\' + ques[0] + '\\' + studentnum.group() + '_' + filename)
                                if not path.group().startswith('AP-'+HWS+'-'+studentnum.group()+'/'+ques[0]):
                                    folderproblem = True
                            else:
                                shutil.copyfile(os.getcwd() + '\\' + cpath,
                                                project_path + '\\' + dirname1 + '\\' + ques[
                                                    0] + '\\' + studentname + filename)
                                folderproblem = True
        # RARFILES
        # elif rarfile.is_rarfile(zips):
        #     folderproblem = True
        #     rar = rarfile.RarFile(zips)
        #     rar.extractall(studentname)
        #     os.chdir(studentname)
        #     for filepath1 in rar.namelist():
        #         for ques1 in Questions:
        #             for j in range(1,len(ques1)):
        #                 path1 = re.search(r'.*[Q|q]' + ques1[0][1] + '.*' + ques1[j] + '$', filepath1)
        #                 if path1:
        #                     filename = re.search(r'\w+' + '.' + ques1[j] + '$', path1.group()).group()
        #                     cpath1 = path1.group().replace('/', '\\')
        #                     if studentnum:
        #                         shutil.copyfile(os.getcwd() + '\\' + cpath1,
        #                                         project_path + '\\' + dirname1 + '\\' + ques1[
        #                                             0] + '\\' + studentnum.group() + '_' + filename)
        #                     else:
        #                         shutil.copyfile(os.getcwd() + '\\' + cpath1,
        #                                         project_path + '\\' + dirname1 + '\\' + ques1[
        #                                             0] + '\\' + studentname + filename)
    # writing in excel
    worksheet.write(cnt, 0, studentname)
    if folderproblem: # student with problems
        worksheet.write(cnt, 1, 'Problem')
    cnt += 1

os.chdir(project_path)
workbook.close()
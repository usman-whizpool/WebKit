# Copyright (C) 2013 Apple Inc. All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
# 1.  Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer. 
# 2.  Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution. 
#
# THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
# DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
# (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
# ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

numProcs=`sysctl -n hw.activecpu`
if [ $? -gt 0 ]
then
    numProcs=`nproc --all 2>/dev/null`
    if [ $? -gt 0 ]
    then
        numProcs=1
    fi
fi

VERBOSE=0
while getopts "v" OPTION
do
    case $OPTION in
        v) VERBOSE=1
            ;;
    esac
done

indexFile=".index"
testList=".all_tests.txt"
tempFile=".temp.txt"
lockDir=".lock_dir"

trap "kill -9 0" SIGINT SIGHUP SIGTERM

echo 0 > ${indexFile}
find . -name 'test_script_*' -depth 1 > ${testList}

function lock_test_list() {
    until mkdir ${lockDir} 2> /dev/null; do sleep 0; done
}

function unlock_test_list() {
    rmdir ${lockDir}
}

if [ -d ${lockDir} ]
then
    rmdir ${lockDir}
fi

total=`wc -l < "${testList}" | sed 's/ //g'`
for proc in `seq ${numProcs}`
do
    (
        lock_test_list
        while [ -s ${testList} ]
        do
            index=`cat ${indexFile}`
            index=$((index + 1))
            echo "${index}" > ${indexFile}
            printf "\r ${index}/${total}"

            nextTest=`tail -n 1 ${testList}`
            sed '$d' < ${testList} > ${tempFile}
            mv ${tempFile} ${testList}
            unlock_test_list

            [ $VERBOSE -eq 1 ] && sh ${nextTest} || sh ${nextTest} 1> /dev/null

            lock_test_list
        done
        unlock_test_list
    )&
done
wait

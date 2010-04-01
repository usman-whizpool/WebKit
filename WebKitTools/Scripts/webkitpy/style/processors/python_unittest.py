# Copyright (C) 2010 Chris Jerdonek (cjerdonek@webkit.org)
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1.  Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
# 2.  Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
# ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
# WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR
# ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

"""Unit tests for python.py."""

import os
import unittest

from python import PythonProcessor


class PythonProcessorTest(unittest.TestCase):

    """Tests the PythonProcessor class."""

    def test_init(self):
        """Test __init__() method."""
        def _mock_handle_style_error(self):
            pass

        processor = PythonProcessor("foo.txt", _mock_handle_style_error)
        self.assertEquals(processor._file_path, "foo.txt")
        self.assertEquals(processor._handle_style_error,
                          _mock_handle_style_error)

    def test_process(self):
        """Test process() method."""
        errors = []

        def _mock_handle_style_error(line_number, category, confidence,
                                     message):
            error = (line_number, category, confidence, message)
            errors.append(error)

        current_dir = os.path.dirname(__file__)
        file_path = os.path.join(current_dir, "python_unittest_input.py")

        processor = PythonProcessor(file_path, _mock_handle_style_error)
        processor.process(lines=[])

        self.assertEquals(len(errors), 1)
        self.assertEquals(errors[0],
                          (2, "pep8/W291", 5, "trailing whitespace"))

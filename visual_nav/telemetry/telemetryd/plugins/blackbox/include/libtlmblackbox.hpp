/**
 * Copyright (c) 2015 Parrot S.A.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the name of the Parrot Company nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE PARROT COMPANY BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * @file libtlmblackbox.c
 *
 */

#ifndef _LIBTLMBLACKBOX_HPP_
#define _LIBTLMBLACKBOX_HPP_

#include "libtelemetry.hpp"

namespace telemetry {

class BlackboxReaderItfCb : public LoggerCb {
public:
	typedef std::map<std::string, std::string> PropertyMap;

	/**
	 * Notification of file header.
	 * @param propertyMap: file header properties.
	 */
	virtual void fileHeader(const PropertyMap &propertyMap) = 0;
};

class BlackboxReaderItf {
public:
	inline BlackboxReaderItf() {}
	inline virtual ~BlackboxReaderItf() {}

	virtual int open(const char *path) = 0;
	virtual void close() = 0;
	virtual int readAll() = 0;
	virtual int readNext() = 0;

	virtual const std::string &getSection(uint32_t sectionId) const = 0;
	virtual uint32_t getVarCount(uint32_t sectionId) const = 0;
	virtual const VarDesc &getVarDesc(uint32_t sectionId, uint32_t varId) const = 0;

	static BlackboxReaderItf *create(BlackboxReaderItfCb *cb);
};

} /* namespace gndctrl */

#endif /* _LIBGNDCTRL_HPP_ */

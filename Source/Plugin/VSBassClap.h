// VSBassClap.h
// The three entry functions clap-wrapper links into every format.

#pragma once

bool tbvb_entry_init (const char* pluginPath);
void tbvb_entry_deinit();
const void* tbvb_entry_get_factory (const char* factoryId);
